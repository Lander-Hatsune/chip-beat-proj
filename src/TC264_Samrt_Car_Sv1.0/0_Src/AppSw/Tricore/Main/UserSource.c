
/******************************************************************************/
/*----------------------------------����---------------------------------------*/
/******************************************************************************/
#include "UserSource.h"
#include "ServeSource.h"
#include "VadcApp.h"
//#include "PicProcess.c"
int timecounter10=0;

/******************************************************************************/
/*---------------------------------�û���������-----------------------------------*/
/******************************************************************************/
uint8 ctldata=0;
int CodePerid;
float distance;
/******************************************************************************/
/*----------------------------------�û�����------------------------------------*/
/******************************************************************************/
//�����������÷�
void motor_duty(int duty)//�����û�����������
{
	if (duty>0)
		SetMotor(FORWARD, duty);
	else
		SetMotor(BACKWARD, -duty);
}
void steer_angle(int duty)
{
	if (duty>0)
		SetSteer(LEFT, duty);
	else if(duty<0)
		SetSteer(RIGHT, -duty);
	else
		SetSteer(MIDDLE, duty);
}

// global variables as windows to watch
uint8* _inp_window;
int* _myangle_window;
int* _myduty_window;

// RemoteControl with manip.py
void RemoteControl(void) {
    uint8 inp = 0;
    int myduty = 0,myangle = 0;
    
    _inp_window = &inp;
    _myangle_window = &myangle;
    _myduty_window = &myduty;
    
    motor_duty(myduty);
    steer_angle(myangle);
    while(TRUE)	{
        inp = Bluetooth_Read_Data();
        if (inp != 0)
            ctldata = inp;
        switch (ctldata) {
        case 'W':
            myduty++;
            ctldata='w';
            motor_duty(myduty);
            steer_angle(myangle);
            Bluetooth_Send_Data(ctldata);
            break;
        case 'S':
            myduty--;
            ctldata='s';
            motor_duty(myduty);
            steer_angle(myangle);
            Bluetooth_Send_Data(ctldata);
            break;
        case 'A':
            myangle+=2;
            ctldata='a';
            motor_duty(myduty);
            steer_angle(myangle);
            Bluetooth_Send_Data(ctldata);
            break;
        case 'D':
            myangle-=2;
            ctldata='d';
            motor_duty(myduty);
            steer_angle(myangle);
            Bluetooth_Send_Data(ctldata);
            break;
        case 'E':
            myangle=0;
            myduty=0;
            ctldata='e';
            motor_duty(myduty);
            steer_angle(myangle);
            Bluetooth_Send_Data(ctldata);
            break;
        case 'Z':
            myangle = 0;
            ctldata='z';
            steer_angle(myangle);
            Bluetooth_Send_Data(ctldata);
            break;
        case 'X':
            myduty = 0;
            ctldata='x';
            motor_duty(myduty);
            Bluetooth_Send_Data(ctldata);
            break;
        case 'C':
            ctldata='c';
            Bluetooth_Send_Data(ctldata);
            break;
        default:
            break;
        }
    }
    _inp_window = NULL;
    _myangle_window = NULL;
    _myduty_window = NULL;
}

int circle_flag = 0;
void SelfDrive(void) {
//&& freq_sum
    // relevant constants --begin
    int mag_delta_thresh = 100;// when to start steering
    double mag_delta_kp = 0.024;
    int steer_limit = 100;     // max steering limit
    int motor_speed = 60;
    int rev_thresh = 800;
    int mag_circle_judge = 5000;//judge to cross a circle
    int mag_circle_sideroad = 7500;//judge to choose a sideroad
    int mag_singalline = 4500;
    int mag_side_doubleline = 4500;
    // constants --end
	
    int mag_sum = 0, mag_delta = 0, myangle = 0;
    int left_mag_sum = 0, right_mag_sum = 0;
    /*****jyf edit 1/15 17:56*****/
    int keep_start = 0, keep_now = 0;
    //edit end
    _myangle_window = &myangle;
    _myduty_window = &motor_speed;

    while (1) {
    	myangle = 0;
    	VADCresult_run();
    	mag_sum = VADCresult[2] + VADCresult[3] + VADCresult[4] + VADCresult[5];
    	// left minus right
    	left_mag_sum = VADCresult[2] + VADCresult[3];
    	right_mag_sum = VADCresult[4] + VADCresult[5];
	
        if (circle_flag == 0) {
            if (right_mag_sum > mag_circle_judge && abs(VADCresult[1] - VADCresult[6]) > 1700) {
                circle_flag = 1;//�Ҳ���ֶ�����
                keep_start = timecounter10;
            } else if (left_mag_sum > mag_circle_judge && abs(VADCresult[1] - VADCresult[6]) > 1700) {
                circle_flag = -1;//�����ֶ�����
                keep_start = timecounter10;
            }
        }
        if (circle_flag != 0) {
            keep_now++;
        }
        if (circle_flag == 1 && keep_now - keep_start < 20) {
            right_mag_sum = mag_side_doubleline;
        } else if (circle_flag == -1 && keep_now - keep_start < 20) {
            left_mag_sum  = mag_side_doubleline;
        }
    	if (circle_flag == 1 && mag_sum > mag_circle_sideroad && keep_now - keep_start > 50) {
            left_mag_sum  = mag_side_doubleline;//�Ҳ���ֶ���������������ֵ
    	} else if (circle_flag == -1 && mag_sum > mag_circle_sideroad && keep_now > 50) {
            right_mag_sum = mag_side_doubleline;//�����ֶ������������ҵ��ֵ
    	}
    	if (circle_flag == 1 && mag_sum < mag_singalline && keep_now > 150) {
            circle_flag = 0;//��ʻ������������ָ�������״̬
            keep_now = 0;
    	} else if (circle_flag == -1 && mag_sum < mag_singalline && keep_now > 150) {
            circle_flag = 0;
            keep_now = 0;
    	}
        
    	mag_delta = left_mag_sum - right_mag_sum;
        if (mag_delta > mag_delta_thresh) {
            myangle = mag_delta_kp * mag_delta;
            if (myangle > steer_limit) myangle = steer_limit;
        } else if (mag_delta < -mag_delta_thresh) {
            myangle = mag_delta_kp * mag_delta;
            if (myangle < -steer_limit) myangle = -steer_limit;
        } else myangle = 0;

        steer_angle(myangle);
        motor_duty(-motor_speed);// why neg?
    }
}


/*****************************������***********************************/
//CPU0������������ѭ�����û���Ҫ�߼�������
void UserCpu0Main(void) {
    if (GetDip(1) == TRUE) {
        SetLed(1, 1);// close the light
        SelfDrive();
    } else RemoteControl();
}

/*
void Conv(int strd, int h, int w) {
    int kernal[3][3] = {{1, 0, -1},
                        {2, 0, -2},
                        {1, 0, -1}};
    for (int i = 0; i <= h - strd + 1; i += strd) {
        for (int j = 0; j <= w - strd + 1; j += strd) {
            int temp_sum = 0;
            for (int ki = 0; ki < 3; ki++)
                for (int kj = 0; kj < 3; kj++)
                    temp_sum += kernal[ki][kj] * pic[i + ki][j + kj];
            if (temp_sum > thresh) {
                convout[i][j] = '#';
            }else if (temp_sum < -thresh) {
                convout[i][j] = '|';
            }
        }
    }
}*/

//CPU1������������ѭ���У�����ͷ��д�ɴ˺˴���������������ͷ��ؼ��㣺
//��Ҫд����ѭ����������AD��ش���
void UserCpu1Main(void) {
    // for test
    //imageRead();
    //delay_ms(10);

    //----------image process and evaluate----------//

    // the picture: unsigned int pic[121][161]
    /*
    int height = 120, width = 160;
    int conv_h = (height + 1) / 2, conv_w = (width + 1) / 2;
    
    int conv_result[121][161];
    Conv(2, *conv_result, 120, (height + 1) / 2, (width + 1) / 2);
    */
}
/**************************************�жϵ��ú���****************************************/
//�ú���ÿ10msִ��һ�Σ����ڸú�������д�����ж�ʱ�����ޣ���Ҫ̫��
uint32 UserInterupt10ms(void)
{
    timecounter10++;
    return 0;
}
//�ú���ÿ100msִ��һ�Σ����ڸú�������д�����ж�ʱ�����ޣ���Ҫ̫��
//��������ȡ���������Ƶ���볬������
uint32 UserInterupt100ms(void)
{
	distance=get_echo_length();
	CodePerid=GetCodePerid();
	return 0;
}
//�ú���ÿ1000msִ��һ�Σ����ڸú�������д�����ж�ʱ�����ޣ���Ҫ̫��
uint32 UserInterupt1000ms(void)
{
	return 0;
}

void UserInteruptIO(void)
{
	IfxPort_togglePin(LED1);
}

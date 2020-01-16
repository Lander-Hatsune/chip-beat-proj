
/******************************************************************************/
/*----------------------------------����---------------------------------------*/
/******************************************************************************/
#include "UserSource.h"
#include "ServeSource.h"
#include "VadcApp.h"
#include "Mpu6050.h"
//#include "PicProcess.c"
int timecounter10 = 0;

/******************************************************************************/
/*---------------------------------�û���������-----------------------------------*/
/******************************************************************************/
uint8 ctldata=0;
int CodePerid = 0;
int CodePerid_prev = 0;
float yaw_angle_start = 0;
float yaw_angle_now = 0;
float keep_start = 0.0, keep_now = 0.0;
float distance;
uint8 reed_state = 0;// 0 with magnet
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

float abs(float num) {
    return num < 0.0 ? -num : num;
}

int circle_flag = 0;
int circle_flag_2 = 0;
void SelfDrive(void) {
    //&& freq_sum
    // relevant constants --begin
	int light_angle = 90;
    int mag_delta_thresh = 100;// when to start steering
    double mag_delta_kp = 0.04;//wait to change
    int steer_limit = 100;     // max steering limit
    int speed_set = 60;
	int speed_min = 20;
    int mag_circle_sum_judge = 9000;//judge to cross a circle
    int mag_circle_oneside_judge = 4000;
    int mag_singalline = 5000;
    int mag_VADC3or4_doubleline = 1000;
    float kp_enc_motor = 1.33;
    float kp_enc_angle = 0.3;
    int CodePerid_target = 4000;//ԭ��������Ϊ6000��17���賿����ʱ��������������Ϊ4000
    float circle_peird = 1;
	float leave_circle_time = 2;
    // constants --end
	
    int motor_speed = 0;
    int mag_sum = 0, mag_delta = 0, myangle = 0;
    int left_mag_sum = 0, right_mag_sum = 0, mag_oneside = 0;
	float keep_start_2 = 0.0, keep_now_2 = 0.0;

    _myangle_window = &myangle;
    _myduty_window = &motor_speed;
    
    
	/*
    //��ת������
    while (1) {//ֱ�߳����� ֱ�����ܵ�����
        myangle = 0;
        motor_speed = 40;
        if (CodePerid < 300) motor_speed = 80;//����ֵ������� 
        steer_angle(myangle);
        motor_duty(-motor_speed);// why neg?
        if (!reed_state) break;
    }
    yaw_angle_start = mpudata_int[6];// counter-clockwise: +  ��¼��ʼ������
    while (1) {
        myangle = -90;//��ת������
        yaw_angle_now = mpudata_int[6];//����������
        motor_speed = 40;
        if (CodePerid < 500) motor_speed = 80;
        if (abs(yaw_angle_now - yaw_angle_start) > light_angle - 15) break;
        steer_angle(myangle);
        motor_duty(-motor_speed);// why neg?
    }
	*/
    
    //��ʼ����Ѳ�߽׶�
    SetLed(2, 1);
    SetLed(3, 1);
    SetLed(4, 1);
    circle_flag = 0;
    while (1) {
    	myangle = 0;
    	VADCresult_run();
    	mag_sum = VADCresult[1] + VADCresult[2] + VADCresult[3] +
            VADCresult[4] + VADCresult[5] + VADCresult[6];
    	// left minus right
    	left_mag_sum  = VADCresult[1] + VADCresult[2];
    	right_mag_sum = VADCresult[5] + VADCresult[6];
        mag_delta = VADCresult[3] - VADCresult[4];
        mag_oneside = VADCresult[5] + VADCresult[6] -VADCresult[1] - VADCresult[2];
        //right minus left
        if (circle_flag == 0) {
            if (mag_sum > mag_circle_sum_judge &&
                mag_oneside > mag_circle_oneside_judge &&
                VADCresult[6] - VADCresult[1] > 2000) {
                
                circle_flag = 1;//�Ҳ���ֶ�����
                SetLed(4, 0);//�Ժ��ע��  0����
                keep_start = (float)timecounter10 / 100;//��ʼ��¼ʱ��
                yaw_angle_start = mpudata_int[6];//��ʼ��¼yaw

            } else if (mag_sum > mag_circle_sum_judge &&
                       mag_oneside < -mag_circle_oneside_judge &&
                       VADCresult[1] - VADCresult[6] > 2000) {

                circle_flag = -1;//�����ֶ�����
                SetLed(3, 0);//�Ժ��ע��
                yaw_angle_start = mpudata_int[6];
                keep_start = (float)timecounter10 / 100;

            }
        }//�ж����뻷��
        if (circle_flag != 0) {
            keep_now = (float)timecounter10 / 100;//����ʱ���ֵ ��λ��s
            if (mpudata_int[6] != 0) //���������ǵ���ֵ
                yaw_angle_now = mpudata_int[6];
            if (keep_now - keep_start < circle_peird) mag_delta = 0;//0.x��֮�ڲ������Ƕ�
        }//���뻷����ʼ��ʱ ��¼������

    	if (circle_flag == 1 && mag_sum > mag_circle_sum_judge &&
            keep_now - keep_start > circle_peird &&
            abs(yaw_angle_now - yaw_angle_start) < light_angle) {

            mag_delta = mag_VADC3or4_doubleline - VADCresult[4];//�Ҳ���ֶ��������ֲ�·��������ֵ

    	} else if (circle_flag == -1 && mag_sum > mag_circle_sum_judge &&
                   keep_now - keep_start > circle_peird &&
                   abs(yaw_angle_now - yaw_angle_start) < light_angle) {

            mag_delta = VADCresult[3] - mag_VADC3or4_doubleline;//�����ֶ��������ֲ�·�����ҵ��ֵ
    	
        }
		
        if (circle_flag == 1 && mag_sum > mag_circle_sum_judge &&
            abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20) {

            mag_delta = VADCresult[3] - mag_VADC3or4_doubleline;//��Ҫ�߳��������ѵ���ֲ��ʱ�������Ҳ���ֵ��һ·˳��

        } else if (circle_flag == -1 && mag_sum > mag_circle_sum_judge &&
                   abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20) {

            mag_delta = mag_VADC3or4_doubleline - VADCresult[4];//��Ҫ�߳��������ѵ���ֲ��ʱ�������Ҳ���ֵ��һ·˳��

        }
		
        if (circle_flag_2 != 1 && circle_flag != 0 && abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20) {
            circle_flag_2 = 1;
            keep_start_2 = timecounter10 / 100;
        }
		
        if (circle_flag_2 == 1) {
            keep_now_2 = timecounter10 / 100;
        }
		
    	if (circle_flag_2 == 1 && circle_flag == 1 && mag_sum < mag_singalline &&
            abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20 &&
            keep_now_2 - keep_start_2 > leave_circle_time) {

            circle_flag = 0;//��ʻ������������ָ�������״̬
            keep_now = 0;
            circle_flag_2 = 0;
            SetLed(4, 1);

    	} else if (circle_flag_2 == 1 && circle_flag == -1 && mag_sum < mag_singalline &&
                   abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20 && 
                   keep_now_2 - keep_start_2 > leave_circle_time) {

            circle_flag = 0;
            keep_now = 0;
            circle_flag_2 = 0;
            SetLed(3, 1);
    	}

        if (mag_delta > mag_delta_thresh) {
            myangle = mag_delta_kp * mag_delta;
            if (myangle > steer_limit) myangle = steer_limit;
        } else if (mag_delta < -mag_delta_thresh) {
            myangle = mag_delta_kp * mag_delta;
            if (myangle < -steer_limit) myangle = -steer_limit;
        } else myangle = 0;
        motor_speed = speed_set;
        motor_speed += kp_enc_motor * (CodePerid_target - CodePerid) / 200;
        motor_speed -= kp_enc_angle * abs(myangle);
        if (motor_speed > 100) motor_speed = 100;
        else if (motor_speed < speed_min) motor_speed = speed_min;
        if (CodePerid < 500) motor_speed = 90; 
        //if (abs(myangle) < 20) motor_speed = 90;//��ֱ��ʱ����
        steer_angle(myangle);
        motor_duty(-motor_speed);// why neg?
    }
	
    //ͣ����� �ȴ���������������ź� 
    yaw_angle_start = mpudata_int[6];
    while (1) {
        yaw_angle_now = mpudata_int[6];
        myangle = -90;
        motor_speed = 40;
        if (CodePerid < 300) motor_speed = 75;
        if (abs(yaw_angle_now - yaw_angle_start) > 80) break;
    }
    keep_start = timecounter10 / 100;
    while (1) {
        keep_now = timecounter10 / 100;
        myangle = 90;
        steer_angle(myangle);
        if (keep_now - keep_start > 0.2) break; 
    }
    while (1) {
        keep_now = timecounter10 / 100;
        myangle = -90;
        steer_angle(myangle);
        if (keep_now - keep_start > 0.4) break;
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
	CodePerid_prev = CodePerid;
	CodePerid = GetCodePerid();
	reed_state = IfxPort_getPinState(&MODULE_P20, 0);
    return 0;
}
//�ú���ÿ100msִ��һ�Σ����ڸú�������д�����ж�ʱ�����ޣ���Ҫ̫��
//��������ȡ���������Ƶ���볬������
uint32 UserInterupt100ms(void)
{
	distance=get_echo_length();//ÿ100ms����һ�γ�����
	MPU6050_Get_Data();//ÿ100ms����һ��������
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

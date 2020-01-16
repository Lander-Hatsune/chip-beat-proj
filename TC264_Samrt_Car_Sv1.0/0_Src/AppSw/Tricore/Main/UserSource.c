
/******************************************************************************/
/*----------------------------------引用---------------------------------------*/
/******************************************************************************/
#include "UserSource.h"
#include "ServeSource.h"
#include "VadcApp.h"
#include "Mpu6050.h"
//#include "PicProcess.c"
int timecounter10 = 0;

/******************************************************************************/
/*---------------------------------用户变量定义-----------------------------------*/
/******************************************************************************/
uint8 ctldata=0;
int CodePerid = 0;
int CodePerid_prev = 0;
int yaw_angle_start = 0;
int yaw_angle_now = 0;
float distance;
uint8 reed_state = 0;// 0 with magnet
/******************************************************************************/
/*----------------------------------用户函数------------------------------------*/
/******************************************************************************/
//函数及函数用法
void motor_duty(int duty)//样例用户自身舵机函数
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

unsigned int abs(int num) {
	if (num < 0) {
		return -num;
	} else {
		return num;
	}
}

int circle_flag = 0;
void SelfDrive(void) {
	//&& freq_sum
    // relevant constants --begin
    int mag_delta_thresh = 100;// when to start steering
    double mag_delta_kp = 0.04;//wait to chagne
    int steer_limit = 100;     // max steering limit
	int speed_set = 60;
    int mag_circle_sum_judge = 8000;//judge to cross a circle
	int mag_circle_oneside_judge = 4000;
    int mag_singalline = 5000;
    int mag_VADC3or4_doubleline = 2000;
	float kp_enc_motor = 1.33;
	float kp_enc_angle = 0.3;
	int CodePerid_target = 6000;
	float circle_peird = 0.5;
	int light_angle = 90;
    // constants --end
	
    int motor_speed = 0;
    int mag_sum = 0, mag_delta = 0, myangle = 0;
    int left_mag_sum = 0, right_mag_sum = 0, mag_oneside;
    /*****jyf edit 1/15 17:56*****/
    float keep_start = 0.0, keep_now = 0.0;
    //edit end
    _myangle_window = &myangle;
    _myduty_window = &motor_speed;
    
    
    //死程序右转出车库
    while (1) {
        myangle = 0;
        motor_speed = 40;
        if (CodePerid < 300) motor_speed = 80; 
        steer_angle(myangle);
        motor_duty(-motor_speed);// why neg?
        if (reed_state) break;
    }
	yaw_angle_start = mpudata_int[6];// counter-clockwise: +
    while (1) {
        myangle = -90;
		yaw_angle_now = mpudata_int[6];
		motor_speed = 40;
		if (CodePerid < 500) motor_speed = 80;
		if (abs(yaw_angle_now - yaw_angle_start) > light_angle - 15) break;
		steer_angle(myangle);
        motor_duty(-motor_speed);// why neg?
    }
    
    //开始自主巡线阶段 
    while (1) {
    	myangle = 0;
    	VADCresult_run();
    	mag_sum = VADCresult[2] + VADCresult[3] + VADCresult[4] + VADCresult[5];
    	// left minus right
    	left_mag_sum  = VADCresult[1] + VADCresult[2];
    	right_mag_sum = VADCresult[5] + VADCresult[6];
		mag_delta = VADCresult[3] - VADCresult[4];
        mag_oneside = VADCresult[5] + VADCresult[6] -VADCresult[1] - VADCresult[2];
		
		if (circle_flag == 0) {
            if (mag_sum > mag_circle_sum_judge && mag_oneside > mag_circle_oneside_judge && abs(VADCresult[1] - VADCresult[6]) > 2000) {
                circle_flag = 1;//右侧出现多赛道
                keep_start = (float)timecounter10 / 100;
				yaw_angle_start = mpudata_int[6];
            } else if (mag_sum > mag_circle_sum_judge && mag_oneside < -mag_circle_oneside_judge && abs(VADCresult[1] - VADCresult[6]) > 2000) {
                circle_flag = -1;//左侧出现多赛道
                yaw_angle_start = mpudata_int[6];
				keep_start = (float)timecounter10 / 100;
            }
        }//判定进入环岛
        if (circle_flag != 0) {
            keep_now = (float)timecounter10 / 100;//keep 单位是s
			if (mpudata_int[6] != 0) {
				yaw_angle_now = mpudata_int[6];				
			}
			if (keep_now - keep_start < circle_peird) mag_delta = 0;
		}//进入环岛开始计时

    	if (circle_flag == 1 && mag_sum > mag_circle_sum_judge && keep_now - keep_start > circle_peird && abs(yaw_angle_now - yaw_angle_start) < light_angle) {
            mag_delta = mag_VADC3or4_doubleline - VADCresult[4];//右侧出现多赛道，分岔路屏蔽左电磁值
    	} else if (circle_flag == -1 && mag_sum > mag_circle_sum_judge && keep_now - keep_start > circle_peird && abs(yaw_angle_now - yaw_angle_start) < light_angle) {
			mag_delta = VADCresult[3] - mag_VADC3or4_doubleline;//左侧出现多赛道，分岔路屏蔽右电磁值
    	}
		
		if (circle_flag == 1 && mag_sum > mag_circle_sum_judge && abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20) {
			mag_delta = VADCresult[3] - mag_VADC3or4_doubleline;//将要走出环岛，已到达分岔口时，屏蔽右侧电磁值，一路顺风
		} else if (circle_flag == -1 && mag_sum > mag_circle_sum_judge && abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20) {
			mag_delta = mag_VADC3or4_doubleline - VADCresult[4];//将要走出环岛，已到达分岔口时，屏蔽右侧电磁值，一路顺风
		}
		
    	if (circle_flag == 1 && mag_sum < mag_singalline && abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20) {
            circle_flag = 0;//若驶出多股赛道，恢复单赛道状态
            keep_now = 0;
    	} else if (circle_flag == -1 && mag_sum < mag_singalline && abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20) {
            circle_flag = 0;
            keep_now = 0;
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
		if (motor_speed < 40) motor_speed = 40;
		if (CodePerid < 500) motor_speed = 100; 
		if (abs(myangle) < 20) motor_speed = 100;
        steer_angle(myangle);
        motor_duty(-motor_speed);// why neg?
    }
	
	//停车入库 等待摄像机给出入库的信号 
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


/*****************************主函数***********************************/
//CPU0主函数，置于循环中用户主要逻辑计算区
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

//CPU1主函数，置于循环中，摄像头读写由此核处理，建议用于摄像头相关计算：
//不要写成死循环，后面有AD相关处理
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
/**************************************中断调用函数****************************************/
//该函数每10ms执行一次，请在该函数中书写程序，中断时间有限，不要太长
uint32 UserInterupt10ms(void)
{
    timecounter10++;
	CodePerid_prev = CodePerid;
	CodePerid = GetCodePerid();
	reed_state = IfxPort_getPinState(&MODULE_P20, 0);
    return 0;
}
//该函数每100ms执行一次，请在该函数中书写程序，中断时间有限，不要太长
//样例，获取编码器输出频率与超声举例
uint32 UserInterupt100ms(void)
{
	distance=get_echo_length();
	MPU6050_Get_Data();//新写的陀螺仪测定
	return 0;
}
//该函数每1000ms执行一次，请在该函数中书写程序，中断时间有限，不要太长
uint32 UserInterupt1000ms(void)
{
	return 0;
}

void UserInteruptIO(void)
{
	IfxPort_togglePin(LED1);
}

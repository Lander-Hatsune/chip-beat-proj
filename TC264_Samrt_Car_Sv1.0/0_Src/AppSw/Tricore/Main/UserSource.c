
/******************************************************************************/
/*----------------------------------引用---------------------------------------*/
/******************************************************************************/
#include "UserSource.h"
#include "ServeSource.h"
#include "VadcApp.h"
#include "Mpu6050.h"
#include "PicProcess.h"
int timecounter10 = 0;

/******************************************************************************/
/*--------用-------------------------户变量定义-----------------------------------*/
/******************************************************************************/
uint8 ctldata=0;
int CodePerid = 0;//编码器频率
int CodePerid_prev = 0;
float yaw_angle_start = 0;//开始yaw
float yaw_angle_now = 0;//更新yaw
float keep_start = 0.0, keep_now = 0.0;//开始时间 更新时间
float wave_distance;//超声波距离
float distance_cross_bar = -1e8;//判断前方有木块障碍的距离范围
uint8 reed_state = 0;// 0 with magnet
int kp_distance = 10810;//编码器累加求路程的比例系数
float distance = 0.0;//绝对路程
int distance_start = 0;//开始路程
int distance_now = 0;//更新路程
int _camera_recog_mode;
// 0：向左转 1：向右转 2：有斑马线 -1：正常状态
/******************************************************************************/
/*----------------------------------用户函数------------------------------------*/
/******************************************************************************/
float abs(float x) {
	return x < 0 ? -x : x;
}
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
/*
float abs(float num) {
    return num < 0.0 ? -num : num;
}
*/
void CrossBarrier() {
    /*
    float start_point = distance;
    float cur_dis = distance - start_point;
    // relevant parameters --start
    int bias_angle = 30;
    int bias_dis = 130;
    int strait_dis = 20;
    // parameters --end
    steer_angle(bias_angle);
    while (cur_dis < bias_dis)
        cur_dis = distance - start_point;
    
    steer_angle(-bias_angle);
    while (cur_dis < bias_dis + strait_dis)
        cur_dis = distance - start_point;
    
    steer_angle(-bias_angle);
    while (cur_dis < bias_dis + strait_dis + bias_dis)
        cur_dis = distance - start_point;
    
    steer_angle(bias_angle);
    */
    return;
}

int circle_flag = 0;
int circle_flag_2 = 0;
int crossbar_flag = 0;
void SelfDrive(void) {//自动驾驶模式
    int i = 0;
    uint8 inp;
    //&& freq_sum
    // relevant constants --begin
    int light_angle = 90;
    int mag_delta_thresh = 100;// when to start steering
    double mag_delta_kp = 0.055;//wait to change
    int steer_limit = 100;     // max steering limit
    int speed_set = 40;
    int speed_min = 20;
    int mag_circle_sum_judge = 9505;//judge to cross a circle
    int mag_circle_oneside_judge = 3200;
    int mag_singalline = 5000;
    int mag_VADC3or4_doubleline = 1000;
    float kp_enc_motor = 1.33;
    float kp_enc_angle = 0.1;//过弯减速
    int CodePerid_target = 3500;//原设置数据为6000，17日凌晨调试时电量充满，调整为4000,37cm/s对应4000
    float circle_peird = 0.3;
    float leave_circle_time = 2;
    int circle_zhouchang = 1000;//环岛的周长 单位厘米
    int mag_sum_cross = 6000;//经过十字路口开始转向时6个传感器的和的设定值
    // constants --end
	
    int motor_speed = 0;
    int mag_sum = 0, mag_delta = 0, myangle = 0;
    int left_mag_sum = 0, right_mag_sum = 0, mag_oneside = 0;
    float keep_start_2 = 0.0, keep_now_2 = 0.0;
    int change_dir = 0;//识别出标志后直接转向 1向左转； -1向右转
    int sczgsz_flag = 0;

    _myangle_window = &myangle;
    _myduty_window = &motor_speed;
    

    //延时
    while (1) {
        if (timecounter10 > 150) break;
        steer_angle(myangle);
        motor_duty(0);
    }

    //右转出车库
    while (1) {//直线出赛道 直到感受到磁力
        myangle = 0;
        motor_speed = 40;
        if (CodePerid < 300) motor_speed = 80;//门阈值启动电机
        steer_angle(myangle);
        motor_duty(-motor_speed);// why neg?
        if (!reed_state) break;
    }

    SetLed(1, 0);
	SetLed(2, 0);
	SetLed(3, 0);
	SetLed(4, 0);
    yaw_angle_start = mpudata_int[6];// counter-clockwise: positive 记录起始陀螺仪
    while (1) {
        myangle = -100;//右转出赛道
        yaw_angle_now = mpudata_int[6];//更新陀螺仪
        motor_speed = 60;
        if (CodePerid < 500) motor_speed = 80;
        if (abs(yaw_angle_now - yaw_angle_start) > light_angle - 10) break;
        steer_angle(myangle);
        motor_duty(-motor_speed);// why neg?
    }

    //开始自主巡线阶段
    SetLed(1, 1);
    SetLed(2, 1);
    SetLed(3, 1);
    SetLed(4, 1);
    circle_flag = 0;
    sczgsz_flag = 0;
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
        inp = Bluetooth_Read_Data();
        if (inp != 0) {
            ctldata = inp;
        }
        if (ctldata == 'D' && sczgsz_flag == 0) {
        	ctldata = 'd';
        	while(1) {
        		inp = Bluetooth_Read_Data();
        		if (inp != 0) {
        			ctldata = inp;
        		}
        		myangle = 0;
        		VADCresult_run();
        		mag_sum = VADCresult[1] + VADCresult[2] + VADCresult[3] +
        				VADCresult[4] + VADCresult[5] + VADCresult[6];
        		// left minus right
        		left_mag_sum  = VADCresult[1] + VADCresult[2];
        		right_mag_sum = VADCresult[5] + VADCresult[6];
        		mag_delta = VADCresult[3] - VADCresult[4];
        		mag_oneside = VADCresult[5] + VADCresult[6] -VADCresult[1] - VADCresult[2];

        		if (mag_sum > mag_sum_cross && sczgsz_flag == 0) {
        			sczgsz_flag = 1;
        			distance_start = distance;
        			keep_start = timecounter10;
        			yaw_angle_start = mpudata_int[6];
        		}
        		if (sczgsz_flag == 1) {
        			keep_now = timecounter10;
        			distance_now = distance;
        			yaw_angle_start = mpudata_int[6];
        			mag_delta = -2500;
        			if (keep_now - keep_start > 900 || abs(yaw_angle_now - yaw_angle_start) > 75 || distance_now - distance_start > 45) {
        				sczgsz_flag = -1;
        				break;
        			}
        		}

        		if (mag_delta > mag_delta_thresh) {
        			myangle = mag_delta_kp * mag_delta;//+ left; - right
        			if (myangle > steer_limit) myangle = steer_limit;
        		} else if (mag_delta < -mag_delta_thresh) {
        			myangle = mag_delta_kp * mag_delta;
        			if (myangle < -steer_limit) myangle = -steer_limit;
        		} else myangle = 0;
        		motor_speed = speed_set;
        		motor_speed += kp_enc_motor * (CodePerid_target - CodePerid) / 200;
        		motor_speed -= kp_enc_angle * abs(myangle);//ｹﾍ莨ﾙ
        		if (motor_speed > 100) motor_speed = 100;
        		else if (motor_speed < speed_min) motor_speed = speed_min;
        		if (CodePerid < 500) motor_speed = 90;
        		steer_angle(myangle);
        		motor_duty(-motor_speed);// why neg?
        	}
        }

        //_camera_recog_mode 0：向左转 1：向右转 2：有斑马线 -1：正常状态

        if (_camera_recog_mode == -1) {//正常状态
        	if (!reed_state) {
        		SetLed(1, 0);
        		SetLed(2, 0);
        		SetLed(3, 0);
        		SetLed(4, 0);
        		break;//停车入库
        	}

        	if (wave_distance < distance_cross_bar) {
        		SetLed(1, 1);
        		SetLed(2, 0);
        		SetLed(3, 0);//中间两个LED亮起
        		SetLed(4, 1);
        		crossbar_flag == 1;//进入避障模式
        		distance_start = distance;
        	}
        	if (crossbar_flag == 1) {
        		distance_now = distance;
        	}

        	if (crossbar_flag == 0) {
        		if (circle_flag == 0) {
        			if (mag_sum > mag_circle_sum_judge &&
        					mag_oneside > mag_circle_oneside_judge &&
							VADCresult[6] - VADCresult[1] > 2000 &&
							timecounter10 > 1000) {

        				circle_flag = 1;//右侧出现多赛道
        				SetLed(1, 1);
        				SetLed(2, 1);
        				SetLed(3, 1);
        				SetLed(4, 0);//亮
        				keep_start = (float)timecounter10 / 100;//开始记录时间
        				yaw_angle_start = mpudata_int[6];//开始记录yaw
        				distance_start = distance;
        			} else if (mag_sum > mag_circle_sum_judge &&
        					mag_oneside < -mag_circle_oneside_judge &&
							VADCresult[1] - VADCresult[6] > 2000 &&
							timecounter10 > 1000) {

        				circle_flag = -1;//左侧出现多赛道
        				SetLed(1, 0);//亮
        				SetLed(2, 1);
        				SetLed(3, 1);
        				SetLed(4, 1);
        				yaw_angle_start = mpudata_int[6];
        				keep_start = (float)timecounter10 / 100;
        				distance_start = distance;
        			}
        		}//判定进入环岛
        		if (circle_flag != 0) {
        			keep_now = (float)timecounter10 / 100;//更新时间的值 单位是s
        			distance_now = distance;
        			if (mpudata_int[6] != 0) //更新陀螺仪的数值
        				yaw_angle_now = mpudata_int[6];
        			if (keep_now - keep_start < circle_peird) mag_delta = 0;//0.x秒之内不调整角度
        		}//进入环岛开始计时 记录陀螺仪

        		if (circle_flag == 1 && mag_sum > mag_circle_sum_judge &&
        				keep_now - keep_start > circle_peird &&
						abs(yaw_angle_now - yaw_angle_start) < light_angle) {

        			mag_delta = mag_VADC3or4_doubleline - VADCresult[4];//右侧出现多赛道，分岔路屏蔽左电磁值

        		} else if (circle_flag == -1 && mag_sum > mag_circle_sum_judge &&
        				keep_now - keep_start > circle_peird &&
						abs(yaw_angle_now - yaw_angle_start) < light_angle) {

        			mag_delta = VADCresult[3] - mag_VADC3or4_doubleline;//左侧出现多赛道，分岔路屏蔽右电磁值

        		}

        		if (circle_flag == 1 && mag_sum > mag_circle_sum_judge - 1000 &&
        				abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20) {

        			mag_delta = VADCresult[3] - mag_VADC3or4_doubleline;//将要走出环岛，已到达分岔口时，屏蔽右侧电磁值，一路顺风

        		} else if (circle_flag == -1 && mag_sum > mag_circle_sum_judge - 1000 &&
        				abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20) {

        			mag_delta = mag_VADC3or4_doubleline - VADCresult[4];//将要走出环岛，已到达分岔口时，屏蔽右侧电磁值，一路顺风

        		}

        		if (circle_flag_2 != 1 && circle_flag != 0 && abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20) {
        			circle_flag_2 = 1;
        			keep_start_2 = timecounter10 / 100;
        		}

        		if (circle_flag_2 == 1) {
        			keep_now_2 = timecounter10 / 100;
        		}

        		if (circle_flag_2 == 1 && circle_flag == 1 && mag_sum < mag_singalline &&
        				abs(abs(yaw_angle_now - yaw_angle_start) - 360) < 20 &&
						keep_now_2 - keep_start_2 > leave_circle_time &&
						distance_now - distance_start > circle_zhouchang) {

        			circle_flag = 0;//若驶出多股赛道，恢复单赛道状态
        			keep_now = 0;
        			circle_flag_2 = 0;
        			SetLed(1, 1);
        			SetLed(2, 1);
        			SetLed(3, 1);
        			SetLed(4, 1);
        		} else if (circle_flag_2 == 1 && circle_flag == -1 && mag_sum < mag_singalline &&
        				abs(abs(yaw_angle_now - yaw_angle_start) - light_angle * 4) < 20 &&
						keep_now_2 - keep_start_2 > leave_circle_time &&
						distance_now - distance_start > circle_zhouchang) {

        			circle_flag = 0;
        			keep_now = 0;
        			circle_flag_2 = 0;
        			SetLed(1, 1);
        			SetLed(2, 1);
        			SetLed(3, 1);
        			SetLed(4, 1);

        		}
        	} else if (crossbar_flag == 1) {
        		CrossBarrier();
        	}
        } else if (_camera_recog_mode == 0 && change_dir == 0 ) {//向左转
        	change_dir =  1;
        	SetLed(1, 0);
        	SetLed(2, 0);
        	SetLed(3, 1);
        	SetLed(4, 1);//左侧两个LED亮
        	yaw_angle_start = mpudata_int[6];
        } else if (_camera_recog_mode == 1 && change_dir == 0) {//向右转
        	change_dir = -1;
        	SetLed(1, 1);
        	SetLed(2, 1);
        	SetLed(3, 0);
        	SetLed(4, 0);//右侧两个LED亮
        	yaw_angle_start = mpudata_int[6];
        }

        /**************穿越十字路口*******************/
        if (change_dir != 0) {
        	yaw_angle_now = mpudata_int[6];
        }

        if (change_dir == 1 && mag_sum > mag_sum_cross) {
        	change_dir =  2;
        } else if (change_dir == -1 && mag_sum > mag_sum_cross) {
        	change_dir = -2;
        }
        if (change_dir == 2 && abs(yaw_angle_now - yaw_angle_start) < light_angle - 10) {//开始左转
        	mag_delta =  2500;//对应myangle=100
        } else if (change_dir == -2 && abs(yaw_angle_now - yaw_angle_start) < light_angle - 10) {//开始右转
        	mag_delta = -2500;//对应myangle=-100
        }
        if (abs(yaw_angle_now - yaw_angle_start) > light_angle - 10) {
        	change_dir = 0;
        	SetLed(1, 1);
        	SetLed(2, 1);
        	SetLed(3, 1);
        	SetLed(4, 1);//完成穿越十字路口，所有灯熄灭
        }
        /**************穿越十字路口代码结束**********/

        if (mag_delta > mag_delta_thresh) {
        	myangle = mag_delta_kp * mag_delta;//+ left; - right
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
        //if (abs(myangle) < 20) motor_speed = 90;//走直线时加速
        steer_angle(myangle);
        motor_duty(-motor_speed);// why neg?
    }//大while(1)结束


    //停车入库 等待干簧管给出入库的信号
    SetLed(1, 0);
    SetLed(2, 0);
    SetLed(3, 0);
    SetLed(4, 0);
    motor_duty(-30);
    while (i++ < 5e7);
    motor_duty(70);
    steer_angle(-100);
    while (1);
    /*
    keep_start = timecounter10 / 100;
    motor_duty(0);
    distance_start = distance;
    while (abs((float)CodePerid) > 300);
    distance_now = distance;
    while (distance_now - distance_start > 200 ) {
        distance_now = distance;
        motor_duty(100);

    	motor_speed = 40;
        motor_speed += kp_enc_motor * (2000 - CodePerid) / 200;
        motor_speed -= kp_enc_angle * abs(myangle);
        if (motor_speed > 100) motor_speed = 100;
        else if (motor_speed < speed_min) motor_speed = speed_min;
        if (-CodePerid < 500) motor_speed = 90;
        steer_angle(0);
        motor_duty(motor_speed);

    }
    //while (abs((float)CodePerid) < 500) motor_duty(100);
    keep_start = timecounter10 / 100;
    motor_duty(50);//倒车
    steer_angle(-100);
    while (keep_now - keep_start < 2) {
    	keep_now = timecounter10;
    }
    motor_duty(0);
    */
    /*
    distance_start = distance;
	while (1) {//倒车
		myangle = 0;
		motor_speed = -60;
		if (CodePerid < 300) motor_speed = -75; 
		distance_now = distance;
        steer_angle(myangle);
        motor_duty(-motor_speed);// why neg?
		if (distance_now - distance_start > 15) break;//倒车距离为15cm
	}
    yaw_angle_start = mpudata_int[6];
    while (1) {
        yaw_angle_now = mpudata_int[6];
        myangle = -90;
        motor_speed = 40;
        if (CodePerid < 300) motor_speed = 75;
        steer_angle(myangle);
        motor_duty(-motor_speed);// why neg?
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
    */
}

/*****************************主函数***********************************/
//CPU0主函数，置于循环中用户主要逻辑计算区
void UserCpu0Main(void) {
    if (GetDip(1) == TRUE) {
        SetLed(1, 1);// close the light
        SetLed(2, 1);
        SetLed(3, 1);
        SetLed(4, 1);
        SelfDrive();
    } else RemoteControl();
}

//CPU1主函数，置于循环中，摄像头读写由此核处理，建议用于摄像头相关计算：
//不要写成死循环，后面有AD相关处理

int _judge[2];
void UserCpu1Main(void) {
    // for test
    //imageRead();
    // delay_ms(500);

    //----------image process and evaluate----------//

    // the picture: unsigned int pic[121][161]
//    int judge_times = 5;// to be twitched
//    int result = Judge();
//    if (result == -1) {
//        _camera_recog_mode = -1;
//        _judge[0] = _judge[1] = 0;
//        return;
//    }
//    _judge[result] += 1;
//    if (_judge[result] > judge_times) {
//        _camera_recog_mode = result;
//        _judge[0] = _judge[1] = 0;
//    }
	_camera_recog_mode = -1;
}
/**************************************中断调用函数****************************************/
//该函数每10ms执行一次，请在该函数中书写程序，中断时间有限，不要太长
uint32 UserInterupt10ms(void)
{
    timecounter10++;//计时器
    CodePerid_prev = CodePerid;
    CodePerid = GetCodePerid();//编码器
    if (CodePerid > 0x3f3f3f3f || CodePerid < 500) CodePerid = 0;
    distance += (float)CodePerid / kp_distance;
    reed_state = IfxPort_getPinState(&MODULE_P20, 0);//干簧管
    MPU6050_Get_Data();//每10ms更新一次陀螺仪
    return 0;
}
//该函数每100ms执行一次，请在该函数中书写程序，中断时间有限，不要太长
//样例，获取编码器输出频率与超声举例
/**********hyper-sonic start**********/
float _queue[7];
int _queuehead = 0, _queuetail = 4;
float _queue_sum;

float QueueAdd(float x) {
    if (x > 400 || x < 10) x = _queue[_queuetail];
    _queuetail = (_queuetail + 1) % 5;
    _queue[_queuetail] = x;
    _queue_sum += x;
    _queuehead = (_queuehead + 1) % 5;
    _queue_sum -= _queue[_queuehead];
    return _queue_sum / 5;
}
uint32 UserInterupt100ms(void) {
    wave_distance = QueueAdd(get_echo_length());//每100ms更新一次超声波

    return 0;
}
/**********hyper-sonic end**********/
//该函数每1000ms执行一次，请在该函数中书写程序，中断时间有限，不要太长
uint32 UserInterupt1000ms(void)
{
	return 0;
}

void UserInteruptIO(void)
{
	IfxPort_togglePin(LED1);
}

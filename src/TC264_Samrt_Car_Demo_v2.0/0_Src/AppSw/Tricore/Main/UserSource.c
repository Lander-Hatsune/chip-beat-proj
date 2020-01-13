
/******************************************************************************/
/*----------------------------------引用---------------------------------------*/
/******************************************************************************/
#include "UserSource.h"
#include "ServeSource.h"
int timecounter10=0;

/******************************************************************************/
/*---------------------------------用户变量定义-----------------------------------*/
/******************************************************************************/
uint8 ctldata=0;
int CodePerid;
float distance;
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

/*****************************主函数***********************************/
//CPU0主函数，置于循环中用户主要逻辑计算区

void UserCpu0Main(void) //样例：蓝牙遥控小车
{
	uint8 a=0;
	int myduty=0,myangle=0;
	 motor_duty(myduty);
	 steer_angle(myangle);
	while(TRUE)
	{
		a=Bluetooth_Read_Data();// zero if no input
		if (a!=0){
		    	ctldata=a;
		    	Bluetooth_Send_Data(a);// return input data
		}
		    switch (ctldata)
		    {

		    case 'w':// speed up
		    	myduty++;
				ctldata='W';
				 motor_duty(myduty);
				 steer_angle(myangle);
				break;
		    case 's':// speed down
		    	myduty--;
				ctldata='S';
				 motor_duty(myduty);
				 steer_angle(myangle);
				break;
		    case 'a':// turn left
		    	myangle+=2;
				ctldata='A';
				 motor_duty(myduty);
				 steer_angle(myangle);
				break;
		    case 'd':// turn right
		    	myangle-=2;
				ctldata='D';
				 motor_duty(myduty);
				 steer_angle(myangle);
				break;
                    case 'z':// steer originate
                        myangle = 0;
                        ctldata = 'Z';
                        steer_angle(myangle);
                        break;
                    case 'x':// motor stop
                        myduty = 0;
                        ctldata = 'X';
                        motor_duty(myduty);
                        break;
		    case 'e':// general stop
		    	myangle=0;
		    	myduty=0;
				ctldata='E';
				motor_duty(myduty);
				steer_angle(myangle);
				break;
		    default:// no input data
		    	break;
		    }
	}
}
//CPU1主函数，置于循环中，摄像头读写由此核处理，建议用于摄像头相关计算：
//不要写成死循环，后面有AD相关处理
void UserCpu1Main(void)
{

}
/**************************************中断调用函数****************************************/
//该函数每10ms执行一次，请在该函数中书写程序，中断时间有限，不要太长
uint32 UserInterupt10ms(void)
{
	return 0;
}
//该函数每100ms执行一次，请在该函数中书写程序，中断时间有限，不要太长
//样例，获取编码器输出频率与超声举例
uint32 UserInterupt100ms(void)
{
	distance=get_echo_length();
	CodePerid=GetCodePerid();
	return 0;
}
//该函数每1000ms执行一次，请在该函数中书写程序，中断时间有限，不要太长
uint32 UserInterupt1000ms(void)
{
	return 0;
}



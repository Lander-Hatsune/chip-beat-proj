
/******************************************************************************/
/*----------------------------------����---------------------------------------*/
/******************************************************************************/
#include "UserSource.h"
#include "ServeSource.h"
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

/*****************************������***********************************/
//CPU0������������ѭ�����û���Ҫ�߼�������

void UserCpu0Main(void) //����������ң��С��
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
//CPU1������������ѭ���У�����ͷ��д�ɴ˺˴���������������ͷ��ؼ��㣺
//��Ҫд����ѭ����������AD��ش���
void UserCpu1Main(void)
{

}
/**************************************�жϵ��ú���****************************************/
//�ú���ÿ10msִ��һ�Σ����ڸú�������д�����ж�ʱ�����ޣ���Ҫ̫��
uint32 UserInterupt10ms(void)
{
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



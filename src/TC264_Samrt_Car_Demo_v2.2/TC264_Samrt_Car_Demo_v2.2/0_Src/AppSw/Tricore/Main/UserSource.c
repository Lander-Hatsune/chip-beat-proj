
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
		a=Bluetooth_Read_Data();
		if (a!=0)
			ctldata=a;
		switch (ctldata)
		{
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

void UserInteruptIO(void)
{
	IfxPort_togglePin(LED1);
}

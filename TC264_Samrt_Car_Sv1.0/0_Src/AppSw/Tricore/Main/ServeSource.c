/******************************************************************************/
/*****************************�û���********************/
/*****************************�벻Ҫ���Ĵ��ļ��еĴ���**********************************/

#include "ServeSource.h"
#include "Hardware.h"
#include "Cpu/Irq/IfxCpu_Irq.h"
#include "SysSe/Bsp/Bsp.h"
#include "IfxScuWdt.h"
#include "Ifx_reg.h"
#include "IfxScuCcu.h"
#include "IfxCcu6.h"
#include "IfxCpu.h"
/***********************************gpio���***********************************************/
//int k1 = 1;
//int k2 = 1;
//int bo1 = 1;
//int bo2 = 1;
//int bo3 = 1;
//int bo4 = 1;

void GpioInit(void)//gpio��ʼ��
{
	//���뿪��
	IfxPort_setPinMode(DIP1, IfxPort_Mode_inputNoPullDevice);
	IfxPort_setPinMode(DIP2, IfxPort_Mode_inputNoPullDevice);
	IfxPort_setPinMode(DIP3, IfxPort_Mode_inputNoPullDevice);
	IfxPort_setPinMode(DIP4, IfxPort_Mode_inputNoPullDevice);

	//LED
	IfxPort_setPinMode(LED1, IfxPort_Mode_outputPushPullGeneral);
	IfxPort_setPinMode(LED2, IfxPort_Mode_outputPushPullGeneral);
	IfxPort_setPinMode(LED3, IfxPort_Mode_outputPushPullGeneral);
	IfxPort_setPinMode(LED4, IfxPort_Mode_outputPushPullGeneral);

	//��ť
	IfxPort_setPinMode(K1, IfxPort_Mode_inputNoPullDevice);
	IfxPort_setPinMode(K2, IfxPort_Mode_inputNoPullDevice);
}

//int eru_j=0;
//
//IFX_INTERRUPT(SRC_SCUERU0_isr, 0, IFX_INTPRIO_SCU_SR0) //IO�жϹ���
//{
//	eru_j++;
////	IfxPort_togglePin(&MODULE_P33, 8);
////	//IfxStm_waitTicks(&MODULE_STM0, 10000000);
////	__enable ();//����ʹ���ж�
//	UserInteruptIO();
//}
//
//void Eru_init(void)
//{
//	IfxPort_setPinMode(&MODULE_P20, 0, IfxPort_Mode_inputPullUp);
//	IfxPort_setPinMode(&MODULE_P33, 8, IfxPort_Mode_outputPushPullGeneral);
//	MODULE_SCU.EICR[3].B.EXIS0 = 0;//һ��EICR��������ESR��EICR3����ESR6��7��15.1��ESR7�ĵڶ���������ҪEXISI1=2��
//	MODULE_SCU.EICR[3].B.REN0  = 0;// ����ͨ��0�������ؼ��
//	MODULE_SCU.EICR[3].B.FEN0  = 1;//ʹ��ͨ��0���½��ؼ��   ��һ����⵽ͨ�����½���EIFR.B.INTF�ͻ���λ
//	MODULE_SCU.EICR[3].B.LDEN0 = 0;//Ϊ�˷���ʹ���������Զ������־λ
//	MODULE_SCU.EICR[3].B.EIEN0 = 1;//The trigger event is enabled
//	MODULE_SCU.EICR[3].B.INP0  = 5;//OGU5 �������ĸ�GGU��Ԫ�������������������ã�Ҳ���Բ���
//	MODULE_SCU.IGCR[2].B.IGP1  = 1;//һ��IGCR��������OGU��Ԫ�������IGCR2����OGU4��OGU5����Ϊ��һ������õ������OGU5������IGP1=1�������OGU4��IGP0=1
//	MODULE_SCU.IGCR[2].B.GEEN1 = 1;//The trigger generation at a change of the pattern detection result is enabled
//	SRC_SCUERU1.B.SRE          =0x01;      //�����жϣ���ͬ�����ͨ����Ӧ��ͬ���ж��������ɲ�ѯ�ֲ�
//	SRC_SCUERU1.B.SRPN         =IFX_INTPRIO_SCU_SR0;//���ȼ�
//	IfxCpu_Irq_installInterruptHandler(&SRC_SCUERU0_isr, IFX_INTPRIO_SCU_SR0);
//}

int GetDip(int k) //��ȡĳ�����������ص�ioֵ
{
	switch (k)
	{
	case 1:
		return IfxPort_getPinState(DIP1);
	case 2:
		return IfxPort_getPinState(DIP2);
	case 3:
		return IfxPort_getPinState(DIP3);
	case 4:
		return IfxPort_getPinState(DIP4);
	default:
		return 2;
	}
}

int GetKey(int k) //��ȡĳ����ť���ص�ioֵ
{
	switch (k)
	{
	case 1:
		return IfxPort_getPinState(K1);
	case 2:
		return IfxPort_getPinState(K2);
	default:
		return 2;
	}
}

void SetLed(int k, int light) //����led��
{
	switch (k)
	{
	case 1:
		IfxPort_setPinState(LED1, (!light << 16) | (light << 0));
		break;
	case 2:
		IfxPort_setPinState(LED2, (!light << 16) | (light << 0));
		break;
	case 3:
		IfxPort_setPinState(LED3, (!light << 16) | (light << 0));
		break;
	case 4:
		IfxPort_setPinState(LED4, (!light << 16) | (light << 0));
		break;
	}
}




/***********************************�����������***********************************************/
//���AsclinApp.h AsclinApp.c


// ���º���ʹ�ô��ڷ���8λ���ݣ����ݸ�ʽΪ0x00��0xFF����Ҫ�����ַ���������ת��ΪascII��
void Bluetooth_Send_Data(uint8 data)
{
	Asclin_Send_Data(data);

}

// ���º���ʹ���첽����ASC��ȡ�յ���8λ��Ϣ�������ж�RX_FIFO���Ƿ������ݣ�������������ݶ�ȡ,��û�����ݣ��򷵻�0��
uint8 Bluetooth_Read_Data(void)
{
	return Asclin_Read_Data();

}
/*****************************************���������************************************************************/
//���PwmDemo.h PwmDemo.c

// one 'float' has been changed into 'int'
uint32 SetMotor(int direction, float pwmDuty)//����������� ����+ռ�ձȣ�%��
{
	if (direction == FORWARD)
	{
		PWM_Duty2 = 0;
		PWM_Duty1 = (int)(pwmDuty  * PWM_Period1/100);
	}
	else if (direction == BACKWARD)
	{
		PWM_Duty1 = 0;
		PWM_Duty2 = (int)(pwmDuty  * PWM_Period2/ 100);
	}
	return 0;
}
// one 'float' has been changed into 'int'
uint32 SetSteer(int direction, float pwmDuty)//����������� ����+ռ�ձȣ�%��
{
	if (direction == LEFT)
	{
		PWM_Duty0 = (int)(MIDPWM* PWM_Period0 / 100-(MIDPWM - MAXLEFTPWM) * pwmDuty * PWM_Period0 / 10000);

	}
	else if (direction == RIGHT)
	{
		PWM_Duty0 = (int)(MIDPWM* PWM_Period0 / 100+(MAXRIGHTPWM - MIDPWM) * pwmDuty * PWM_Period0 / 10000);
	}
	else if (direction == MIDDLE)
	{
		PWM_Duty0 =  MIDPWM* PWM_Period0 / 100;
	}
	return 0;
}
/******************************�����ж����************************************************/
//�������TimDemo.h TimDemo.c
///************************************��������غ���********************************************/
//

int GetCodePerid() //��ȡ������Ƶ�� Hz
{
	if(CoderAflag==0)
		return IfxGtm_Cmu_getFxClkFrequency(&MODULE_GTM , IfxGtm_Cmu_Fxclk_2, TRUE)/TimPwmPeridB;
	else
		return -1*IfxGtm_Cmu_getFxClkFrequency(&MODULE_GTM , IfxGtm_Cmu_Fxclk_2, TRUE)/TimPwmPeridB;
}
//
///************************************������غ���********************************************/
//


//�������������źţ�һ������20us�ĸߵ�ƽ
//uint8 capflag;
void cap_trigger(void)
{

	IfxPort_setPinState(Ultratrigger, IfxPort_State_high);
	delay_us(30);
	IfxPort_setPinState(Ultratrigger, IfxPort_State_low);
}
//��ȡ�������ŷ��ؾ���
float get_echo_length(void)
{
	float length;
	length= InDuty /58 ; // mm
	return length;
}
//
///************************************MPU6050��غ���********************************************/
float Yaw=0;
float Pitch=0;
float Roll=0;



///*******************************************����ͷ��غ���*******************************************************/
void imageRead(void)//���ô��ڷ�������ͷ���ݣ�������ͷ��λ�����
{
	uint16 m=0;
	uint16 n=0;
	uint16 k=0;

	//��ʱ��ֹ�ж�
//	unsigned char pic[121][161];   //����ֵ


	if((row>=150)&&(flag3>=5))
	{
		//uint8 sci_image_start[8]={1,254,1,254,1,254,1,254};
		//		IfxCpu_disableInterrupts();

		MODULE_GTM.TIM[0].CH1.CTRL.B.TIM_EN	= 0;	/* Enable TIM0 Channle 0. */
		MODULE_GTM.TIM[0].CH2.CTRL.B.TIM_EN	= 0;	/* Enable TIM0 Channle 1. */
		MODULE_GTM.TIM[1].CH3.CTRL.B.TIM_EN	= 0;	/* Enable TIM0 Channle 2. */

		//		Asclin_Send_String(sci_image_start,8);
		for(k=0;k<4;k++)
		{
			//			SCI_Send(0x01);
			Asclin_Send_Data(0x01);
			delay(0.0001);
			//			SCI_Send(0xfe);
			Asclin_Send_Data(0xff);// adjusted from 0xfe
			delay(0.0001);
		}

		delay(0.001);
		for(m=0;m<120;m++)// adjusted from 100, should be 120
		{
			for(n=0;n<160;n++)// adjusted from 150, should be 160
			{
				Asclin_Send_Data(pic[m][n]);
				delay(0.0001);
			}
		}

		flag3=0;
		//		IfxCpu_enableInterrupts();
		MODULE_GTM.TIM[0].CH1.CTRL.B.TIM_EN	= 1;	/* Enable TIM0 Channle 0. */
		MODULE_GTM.TIM[0].CH2.CTRL.B.TIM_EN	= 1;	/* Enable TIM0 Channle 1. */
		MODULE_GTM.TIM[1].CH3.CTRL.B.TIM_EN	= 1;	/* Enable TIM0 Channle 2. */
	}
}


///*********************************��ʱˢ���÷�����*********************************************/

//uint32 test7=0,test8=0;

uint32 ServeInterupt10ms(void)
{
	//������ˢ�º���10ms
	IfxGtm_Tom_Ch_setCompareOne(&MODULE_GTM.TOM[1],  IfxGtm_Tom_Ch_15, PWM_Duty0);
	IfxGtm_Tom_Ch_setCompareOne(&MODULE_GTM.TOM[0], IfxGtm_Tom_Ch_2, PWM_Duty1);
	IfxGtm_Tom_Ch_setCompareOne(&MODULE_GTM.TOM[0], IfxGtm_Tom_Ch_3, PWM_Duty2);

//	test7++;
	return 0;
}

uint32 ServeInterupt100ms(void)//
{

	//������100ms���ֺ���
	//��ȡ����
	 MPU6050_Get_Data();
	 //�궨���궨���ע��
	 MPU6050_Calibrate();
	 //����
	 MPU6050_int(0.1);
	 //�����
	 Roll=mpudata_int[4];
	 Pitch=mpudata_int[5];
	 Yaw=mpudata_int[6];
//IO����
//	k1 = GetKey(1);
//	k2 = GetKey(2);
//
//	bo1 = GetDip(1);
//	bo2 = GetDip(2);
//	bo3 = GetDip(3);
//	bo4 = GetDip(4);
//
	SetLed(1,GetDip(1));
	//SetLed(2,GetDip(2));// ��ע��
	//SetLed(3,GetDip(3));
	//SetLed(4,GetDip(4));
//AD
	//VADCresult_run();
	cap_trigger();

	return 0;
}

uint32 ServeInterupt1000ms(void)
{
	//1sִ�еĺ���
	//	cap_trigger();
	//VADCresult_run();

	return 0;
}

void delay_us(uint32 time)
{
	IfxStm_waitTicks(&MODULE_STM0, IfxStm_getTicksFromMicroseconds(&MODULE_STM0, time));
}

void delay_ms(uint32 time)
{
	IfxStm_waitTicks(&MODULE_STM0, IfxStm_getTicksFromMicroseconds(&MODULE_STM0, 1000*time));
}

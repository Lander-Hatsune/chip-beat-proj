#include "CameraOV7620.h"
#include "Hardware.h"


//SCCBͨѶ����      SDA:P02.4    SCL:P02.5
#define SCCB_SDA  &MODULE_P02, 4
#define SCCB_SCL  &MODULE_P02, 5
#define SDAOUT   IfxPort_setPinMode(SCCB_SDA, IfxPort_Mode_outputOpenDrainGeneral)
#define SDAIN   IfxPort_setPinMode(SCCB_SDA, IfxPort_Mode_inputNoPullDevice)
#define SCLOUT   IfxPort_setPinMode(SCCB_SCL, IfxPort_Mode_outputOpenDrainGeneral)
#define SCLIN   IfxPort_setPinMode(SCCB_SCL, IfxPort_Mode_inputNoPullDevice)
#define SDA_HIGH   	IfxPort_setPinState(SCCB_SDA, IfxPort_State_high)
#define SDA_LOW   	IfxPort_setPinState(SCCB_SDA, IfxPort_State_low)
#define SCL_HIGH   	IfxPort_setPinState(SCCB_SCL, IfxPort_State_high)
#define SCL_LOW   	IfxPort_setPinState(SCCB_SCL, IfxPort_State_low)

unsigned char HrefFlag;
int row=0;           //ͼ���������
int column=0;        //ͼ���������
unsigned char pic[121][161];   //����ֵ
unsigned char cycle;
unsigned char flag3;    //��������ʶ
/*************************************************
Function: SCCB_Wait
Description: delay
Input: no
Output: no
More:no
 *************************************************/
void SCCB_Wait(void)
{
	delay_us(1);
}



/*************************************************
Function: SCCB_Start
Description: signal of start
Input: no
Output: no
More:no
 *************************************************/
void SCCB_Start(void)
{
	SDAOUT;
	SDA_HIGH;
	SCL_HIGH;
	SCCB_Wait();
	SDA_LOW;
	SCCB_Wait();
	SCL_LOW;
}



/*************************************************
Function: SCCB_Stop
Description: signal of stop
Input: no
Output: no
More:no
 *************************************************/
void SCCB_Stop(void)
{
	SDAOUT;
	SDA_LOW;
	SCCB_Wait();
	SCL_HIGH;
	SCCB_Wait();
	SDA_HIGH;
	SCCB_Wait();
}

/*************************************************
Function: SCCB_SendAck
Description: send ack to slave
Input: signal of ack
Output: no
More:no
 *************************************************/
void SCCB_SendAck(uint8 ack){
	SDAOUT;
	IfxPort_setPinState(SCCB_SDA, ack);
	SCL_HIGH;
	SCCB_Wait();
	SCL_LOW;
}



/*************************************************
Function: SCCB_SendByte
Description: send data to SCCB register
Input: uint8 of data
Output: return ack 1:receive ack 0:no ack
More:no
 *************************************************/
uint8 SCCB_SendByte(unsigned char bytedata){
	unsigned char i;
	uint8 ack;
	SDAOUT;
	for(i=0;i<8;i++)
	{
		if(bytedata & 0x80)
			SDA_HIGH;
		else
			SDA_LOW;
		bytedata <<= 1;
		SCCB_Wait();
		SCL_HIGH;
		SCCB_Wait();
		SCL_LOW;
		SCCB_Wait();
	}

	SDA_HIGH;
	SDAIN;
	SCCB_Wait();
	SCL_HIGH;
	SCCB_Wait();
	ack = IfxPort_getPinState(SCCB_SDA);
	SCL_LOW;
	SCCB_Wait();
	return ack;
}





/******************************************************
Function: SCCB_ReceiveByte
Description: receive data from SCCB register
Input: no
Output: data
More:no
 ********************************************************/
unsigned char SCCB_ReceiveByte(void)
{
	unsigned char i;
	unsigned char bytedata = 0;
	SDAIN;
	for(i=0;i<8;i++)
	{
		SCL_HIGH;
		SCCB_Wait();



		bytedata <<= 1;



		if(IfxPort_getPinState(SCCB_SDA))
		{
			bytedata |= 0x01;
		}
		SCL_LOW;
		SCCB_Wait();
	}



	return bytedata;
}
/******************************************************
Function: SCCB_ByteWrite
Description: write the data to the address
Input: device 0xC0 write to OV6620
 0XC1 read from OV6620
 0x42 write to OV7620
 0x43 read from OV7620
Output: no
More:no
 ********************************************************/



void SCCB_WriteRegister(unsigned char device,unsigned char address,unsigned char
		bytedata)
{
	unsigned char i;
	uint8 ack;
	for(i=0;i<20;i++)
	{
		SCCB_Start();
		ack = SCCB_SendByte(device);
		if(ack==1)
		{
			SCCB_Stop();
			continue;
		}

		ack = SCCB_SendByte(address);
		if(ack==1)
		{
			SCCB_Stop();
			continue;
		}

		ack = SCCB_SendByte(bytedata);
		if(ack==1)
		{
			SCCB_Stop();
			continue;
		}
		SCCB_Stop();
		if(ack==0) break; //file://��/��������ѭ��
	}
}

//uint8 SCCB_ReadRegister(unsigned char device,unsigned char address)
//{
//	uint8 data = 0;
//	unsigned char i;
//	uint8 ack;
//	for(i=0;i<20;i++)
//	{
//		SCCB_Start();
//		ack = SCCB_SendByte(device);
//		if(ack==1)
//		{
//			SCCB_Stop();
//			continue;
//		}
//
//		ack = SCCB_SendByte(address);
////		if(ack==1)
////		{
////			SCCB_Stop();
////			continue;
////		}
//
//		data=SCCB_ReceiveByte();
//		SCCB_Stop();
//		if(ack==0) break; //file://��/��������ѭ��
//	}
//	return data;
//}


/******************************************************
Function: camera_set
Description: no
Input: no
Output: no
More:no
 ********************************************************/
void camera_set(void) {

	SDAOUT;
	SCLOUT;

	//SCCB_ByteWrite(0xC0,0x06,0xC0); //ov6620 ���ú���
	//SCCB_ByteWrite(0xC0,0x03,0x80);
	//SCCB_ByteWrite(0xC0,0x0C,0x20);

	SCCB_WriteRegister(0x42,0x12,0x80); //7620 �������� ȱʡֵ 0x24
//	SCCB_WriteRegister(0x42,0x06,0xA0); //7620 ���ȵ��� 0xff ��� 0x00 ��С
//	SCCB_WriteRegister(0x42,0x03,0x80); //7620 �Աȶȵ���
	SCCB_WriteRegister(0x42,0x11,0x03);   //����ʱ��Ƶ��
	SCCB_WriteRegister(0x42,0x14,0x24);   //�ֱ���320*240
	SCCB_Wait();

}

/************************��ʱС����***********************/
void delay(float32 timeSec)
{
    uint32 stmCount      = (uint32)(IfxScuCcu_getStmFrequency() * timeSec);
    uint32 stmCountBegin = STM0_TIM0.U;

    while ((uint32)(STM0_TIM0.U - stmCountBegin) < stmCount)
    {
       ;
    }
}


/************************����ͷ��ʼ��***********************/
void CameraInit(void)
{
	//����ͷ�������ݶ�ȡ����
	IfxPort_setPinMode(&MODULE_P00, 0, IfxPort_Mode_inputNoPullDevice);
	IfxPort_setPinMode(&MODULE_P00, 1, IfxPort_Mode_inputNoPullDevice);
	IfxPort_setPinMode(&MODULE_P00, 2, IfxPort_Mode_inputNoPullDevice);
	IfxPort_setPinMode(&MODULE_P00, 3, IfxPort_Mode_inputNoPullDevice);
	IfxPort_setPinMode(&MODULE_P00, 4, IfxPort_Mode_inputNoPullDevice);
	IfxPort_setPinMode(&MODULE_P00, 5, IfxPort_Mode_inputNoPullDevice);
	IfxPort_setPinMode(&MODULE_P00, 6, IfxPort_Mode_inputNoPullDevice);
	IfxPort_setPinMode(&MODULE_P00, 7, IfxPort_Mode_inputNoPullDevice);
//	GTM_Clocks_Init();
	//CameraTim_init();             // input interrupt initial
	camera_set();                //SCCB set
}




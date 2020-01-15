#ifndef _SERVESOURCE_H_
#define _SERVESOURCE_H_
/******************************************************************************/
/*****************************�û���********************/
/*****************************�벻Ҫ���Ĵ��ļ��еĴ���**********************************/
/**********************************ͷ�ļ�֧��********************************************/
#include <Ifx_Types.h>
#include <stdio.h>
#include "Bsp/Bsp.h"
#include "_PinMap/IfxGtm_PinMap.h"
#include "ConfigurationIsr.h"
#include "Cpu/Irq/IfxCpu_Irq.h"
#include "Port/Std/IfxPort.h"
#include <Stm/Std/IfxStm.h>
#include <Src/Std/IfxSrc.h>
#include "Gtm/Std/IfxGtm_Cmu.h"
#include "Gtm/Std/IfxGtm_Tom.h"
#include "Cpu/Std/Ifx_Types.h"
#include "Ifxgtm_reg.h"
#include "Compilers.h"
#include "Configuration.h"
/***********************************gpio���***********************************************/
IFX_EXTERN void GpioInit(void); //gpio��ʼ��
//void Eru_init(void); //io�ж� ��ʼ��
/***********************************���뿪�����***********************************************/
#define DIP1 &MODULE_P21, 2  //���뿪��0����
#define DIP2 &MODULE_P21, 3  //���뿪��1����
#define DIP3 &MODULE_P21, 4  //���뿪��2����
#define DIP4 &MODULE_P21, 5  //���뿪��3����
IFX_EXTERN int GetDip(int k); //��ȡĳ�����������ص�ioֵ
/***********************************LED���***********************************************/
#define LED1 &MODULE_P33, 8  //LED0����
#define LED2 &MODULE_P33, 9  //LED1����
#define LED3 &MODULE_P33, 10 //LED2����
#define LED4 &MODULE_P33, 11 //LED3����
IFX_EXTERN void SetLed(int k, int light); //����led��
/***********************************��ť���***********************************************/
#define K1 &MODULE_P15, 1 //K1
#define K2 &MODULE_P20, 13 //K2
IFX_EXTERN int GetKey(int k);

/**********************************�����������***************************************/
#define BAUDRATE 115200 //����������// adjusted from 9600
IFX_EXTERN uint8 Bluetooth_Read_Data(void);
IFX_EXTERN void Bluetooth_Send_Data(uint8 data);
IFX_EXTERN int GetDip(int k);
IFX_EXTERN void GpioInit(void);
/******************************���������************************************************/
#define FORWARD 1
#define BACKWARD 0
#define LEFT 1
#define RIGHT 3
#define MIDDLE 2
#define MAXLEFTPWM 5
#define MIDPWM 7.5
#define MAXRIGHTPWM 10
// two 'float's have been changed into 'int's
IFX_EXTERN uint32 SetMotor(int direction, float pwmDuty);//����������� ����+ռ�ձȣ�%��
IFX_EXTERN uint32 SetSteer(int direction, float pwmDuty);//����������� ����+ռ�ձȣ�%��


/******************************�����ж����************************************************/

#define ISR_PRIORITY_TIM0_CH1     13     //�����ж����ȼ�
#define ISR_PRIORITY_TIM0_CH2     15     //���ж����ȼ�
#define ISR_PRIORITY_TIM1_CH3     14     //���ж����ȼ�
#define ISR_PRIORITY_TIM2_CH0     20     //�����ж����ȼ�   P02.8
#define ISR_PRIORITY_TIM2_CH5     11     //�������ж����ȼ�P20.9
#define ISR_PRIORITY_TIM2_CH6     12     //�������ж����ȼ�P20.9
#define IFX_INTPRIO_SCU_SR0       9      //IO�ж����ȼ�P20.0

///************************************��������غ���********************************************/
#define CoderA &MODULE_P20, 9  //����������A����
IFX_EXTERN int GetCodePerid(); //��ȡ������Ƶ�� Hz

///************************************������غ���********************************************/
#define Ultratrigger     &MODULE_P02, 6  //����trigger����
IFX_EXTERN void cap_trigger(void);
IFX_EXTERN float get_echo_length(void);

///*******************************************����ͷ��غ���*******************************************************/
extern int row;           //ͼ���������
extern int column;        //ͼ���������
extern unsigned char pic[121][161];   //����ֵ
#define Camera_ID     0x42                  //Camera_ID
IFX_EXTERN void imageRead(void);  //���ô��ڷ�������ͷ���ݣ�������ͷ��λ�����

///*********************************��ʱˢ���÷�����*********************************************/
IFX_EXTERN uint32 ServeInterupt10ms(void); //������10ms
IFX_EXTERN uint32 ServeInterupt100ms(void);//������100ms
IFX_EXTERN uint32 ServeInterupt1000ms(void);//������1000ms
IFX_EXTERN void delay_ms(uint32 time); //��ʱ ��λms
IFX_EXTERN void delay_us(uint32 time); //��ʱ ��λus
///********************************��������غ���*********************************************/
extern float Yaw;
extern float Pitch;
extern float Roll;
///*******************************************AD��غ���*******************************************************/
extern unsigned int  VADCresult[9];//AD����洢λ�� 0.0---0.8 AN0....AN8
//����ִ����cpu1����������
#endif /* 0_SRC_APPSW_TRICORE_MAIN_SERVESOURCE_H_ */

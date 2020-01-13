/*
 * Asclin_app.c
 *
 *  Created on: 2018��1��2��
 *      Author: TEC
 */
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "AsclinApp.h"
#include "Hardware.h"


/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
// used globally
static IfxAsclin_Asc asc;
#define ASC_TX_BUFFER_SIZE 64
static uint8 ascTxBuffer[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
#define ASC_RX_BUFFER_SIZE 64
static uint8 ascRxBuffer[ASC_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
IFX_INTERRUPT(asclin0TxISR, 0, IFX_INTPRIO_ASCLIN0_TX)
{
    IfxAsclin_Asc_isrTransmit(&asc);
}
IFX_INTERRUPT(asclin0RxISR, 0, IFX_INTPRIO_ASCLIN0_RX)
{
    IfxAsclin_Asc_isrReceive(&asc);
}
IFX_INTERRUPT(asclin0ErISR, 0, IFX_INTPRIO_ASCLIN0_ER)
{
    IfxAsclin_Asc_isrError(&asc);
}

void AsclinAsc_init(void)
{

	/* disable interrupts */ //���д��뽫CUP�жϹرղ���״̬����interruptState���б�ʾ
	//    boolean              interruptState = IfxCpu_disableInterrupts();

    /* create module config */
    IfxAsclin_Asc_Config ascConfig;   //����һ��ascConfig�Ľṹ�壬���ڱ�ʾasc����
    //IfxAsclin_Asc_initModuleConfig(&ascConfig, &MODULE_ASCLIN3); //�����õ�ASCLIN1����ʼ���ոն����asc�ṹ��
    IfxAsclin_Asc_initModuleConfig(&ascConfig, &MODULE_ASCLIN1); //�����õ�ASCLIN1����ʼ���ոն����asc�ṹ��
    /* set the desired baudrate */
    ascConfig.baudrate.prescaler    = 4;
    ascConfig.baudrate.baudrate     = BAUDRATE; /* FDR values will be calculated in initModule */

    // ISR priorities and interrupt target
    ascConfig.interrupt.txPriority = IFX_INTPRIO_ASCLIN0_TX;
    ascConfig.interrupt.rxPriority = IFX_INTPRIO_ASCLIN0_RX;
    ascConfig.interrupt.erPriority = IFX_INTPRIO_ASCLIN0_ER;
    ascConfig.interrupt.typeOfService =   IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());

    ascConfig.txBuffer = &ascTxBuffer;
    ascConfig.txBufferSize = ASC_TX_BUFFER_SIZE;

    ascConfig.rxBuffer = &ascRxBuffer;
    ascConfig.rxBufferSize = ASC_RX_BUFFER_SIZE;


    /* pin configuration */ //��������
    const IfxAsclin_Asc_Pins pins = {
        NULL,                     IfxPort_InputMode_pullUp,        /* CTS pin not used */
        //&IfxAsclin3_RXE_P00_1_IN, IfxPort_InputMode_pullUp,        /* Rx pin */
//		&IfxAsclin2_RXG_P02_0_IN, IfxPort_InputMode_pullUp,        /* Rx pin */
//        NULL,                     IfxPort_OutputMode_pushPull,     /* RTS pin not used */
        //&IfxAsclin3_TX_P00_0_OUT, IfxPort_OutputMode_pushPull,
		/* Tx pin */

		&IfxAsclin1_RXE_P11_10_IN, IfxPort_InputMode_pullUp,        /* Rx pin */
		        NULL,                     IfxPort_OutputMode_pushPull,     /* RTS pin not used */

		&IfxAsclin1_TX_P11_12_OUT, IfxPort_OutputMode_pushPull,     /* Tx pin */
		        IfxPort_PadDriver_cmosAutomotiveSpeed1

//		&IfxAsclin2_TX_P14_2_OUT, IfxPort_OutputMode_pushPull,     /* Tx pin */
//        IfxPort_PadDriver_cmosAutomotiveSpeed1
    };
    ascConfig.pins = &pins;


    /* initialize module */
    IfxAsclin_Asc_initModule(&asc, &ascConfig);

    IfxCpu_enableInterrupts();
}




// ���º���ʹ�ô��ڷ���8λ���ݣ����ݸ�ʽΪ0x00��0xFF����Ҫ�����ַ���������ת��ΪascII��
void Asclin_Send_Data(uint8 Asclin_Send_Data)
{
	IfxAsclin_Asc_blockingWrite(&asc,Asclin_Send_Data);
	//���ô��ں������ͺ�����ʹ��ASC1������һ��8λ��

}

// ���º���ʹ���첽����ASC��ȡ�յ���8λ��Ϣ�������ж�RX_FIFO���Ƿ������ݣ�������������ݶ�ȡ,��û�����ݣ��򷵻�0��
uint8 Asclin_Read_Data(void)
{
	if(IfxAsclin_Asc_getReadCount(&asc) >0)
	{
		return IfxAsclin_Asc_blockingRead(&asc);
	}

	return 0;

}


//���º������Խ�һ��uint8����ͨ��asclin��������Ҫ���ȸ������鳤��
// Asclin_String ΪҪ���͵����� lengthΪ�����鳤��
//example  Asclin_Send_String(IMAGE,7);
//void Asclin_Send_String(uint8* Asclin_String, uint32 String_Length)
//{
//	while( (String_Length>0) & IfxAsclin_Asc_flushTx(&g_AsclinAsc.drivers.asc1,TIME_INFINITE) )
//	//���length>0 ˵��û�з��� ��������� //���TX��FIFOΪ�գ�����Է���
//	{
//			Asclin_Send_Data(*Asclin_String);
//			Asclin_String ++;
//			String_Length --;
//	}
//}



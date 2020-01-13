#include "SysSe/Bsp/Bsp.h"
#include "Scu\Std\IfxScuWdt.h"
//#include "Stm.h"
#include "Ifx_reg.h"
extern unsigned char HrefFlag;
extern int row;           //图像矩阵行数
extern int column;        //图像矩阵列数
extern unsigned char pic[121][161];   //像素值
extern unsigned char cycle;
extern unsigned char flag3;    //场数量标识
void SCCB_Wait();
void SCCB_Start();
void SCCB_Stop();
void SCCB_SendAck(uint8 );
uint8 SCCB_SendByte(unsigned char);
unsigned char SCCB_ReceiveByte();
void SCCB_WriteRegister(unsigned char ,unsigned char ,unsigned char);
//uint8 SCCB_ReadRegister(unsigned char ,unsigned char);
void camera_set();

void delay(float32 timeSec);
void CameraInit(void);

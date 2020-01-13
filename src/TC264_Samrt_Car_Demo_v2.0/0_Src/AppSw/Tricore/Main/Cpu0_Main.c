/**

 * \file Cpu0_Main.c
 * \brief System initialisation and main program implementation.
 *
 * \version iLLD_Demos_1_0_0_11_0
 * \copyright Copyright (c) 2014 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/


#include "ServeSource.h"
#include "Hardware.h"
#include "UserSource.h"
#include "Cpu0_Main.h"
#include "SysSe/Bsp/Bsp.h"
#include "Scu\Std\IfxScuWdt.h"
#include "IfxPort.h"
#include "IfxStm.h"


uint8 initflag;
/******************************************************************************/
/*------------------------Inline Function Prototypes--------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
App_Cpu0 g_AppCpu0; /**< \brief CPU 0 global data */

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

/** \brief Main entry point after CPU boot-up.
 *
 *  It initialise the system and enter the endless loop that handles the demo
 */
int core0_main(void)
{
    /*
     * !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdog in the demo if it is required and also service the watchdog periodically
     * */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());

    /* Initialise the application state */
    g_AppCpu0.info.pllFreq = IfxScuCcu_getPllFrequency();
    g_AppCpu0.info.cpuFreq = IfxScuCcu_getCpuFrequency(IfxCpu_getCoreIndex());
    g_AppCpu0.info.sysFreq = IfxScuCcu_getSpbFrequency();
    g_AppCpu0.info.stmFreq = IfxStm_getFrequency(&MODULE_STM0);
    IfxCpu_disableInterrupts();
    initflag=0;
    /* Demo init */
    GpioInit();//初始化编码开关
    AsclinAsc_init();//初始化串口SCI
    IfxStmDemo_init(); // 初始化定时器
    GTM_Clocks_Init();//GTM时钟初始化， 包含TOM（PWM） 时钟
    TOM0_init(); //PWM0 output --- P20.11
    TOM1_init();//PWM1 output--- P10.2
    TOM2_init();//PWM2 output--- P10.3
    Tim_init();//摄像头 编码器 超声 输入捕获
    UltrasoundInit();//超声初始化
    //CameraInit();//摄像头初始化
    mpu6050_Init();//初始化iic Mpu6050
    CoderInit();//编码器初始化
    VADC_init();//AD初始化
    initflag=1;
    /* Enable the global interrupts of this CPU */
    IfxCpu_enableInterrupts();

    /* background endless loop */
    while (TRUE)
    {
    	 UserCpu0Main();
    }

    return 0;
}


/** \} */

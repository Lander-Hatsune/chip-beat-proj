/**
 * \file IfxGtm_Tim_In.h
 * \brief GTM IN details
 * \ingroup IfxLld_Gtm
 *
 * \version iLLD_1_0_1_7_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 *
 * \defgroup IfxLld_Gtm_Tim_In TIM Input Interface
 * \ingroup IfxLld_Gtm_Tim
 * \defgroup IfxLld_Gtm_Tim_In_DataStructures Data Structures
 * \ingroup IfxLld_Gtm_Tim_In
 * \defgroup IfxLld_Gtm_Tim_In_Enumerations Enumerations
 * \ingroup IfxLld_Gtm_Tim_In
 * \defgroup IfxLld_Gtm_Tim_In_Funtions Funtions
 * \ingroup IfxLld_Gtm_Tim_In
 */

#ifndef IFXGTM_TIM_IN_H
#define IFXGTM_TIM_IN_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_PinMap/IfxGtm_PinMap.h"
#include "Gtm/Std/IfxGtm_Tim.h"
#include "Gtm/Std/IfxGtm_Cmu.h"
#include "Cpu/Std/IfxCpu.h"
#include "_Utilities/Ifx_Assert.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Tim_In_Enumerations
 * \{ */
/** \brief Config Filter Mode
 */
typedef enum
{
    IfxGtm_Tim_In_ConfigFilterMode_immediateEdgePropagation,      /**< \brief Immediate edge propagation mode */
    IfxGtm_Tim_In_ConfigFilterMode_individualDeglitchTimeUpDown,  /**< \brief Individual deglitch time mode (Up Down) */
    IfxGtm_Tim_In_ConfigFilterMode_individualDeglitchTimeHold,    /**< \brief Individual deglitch time mode (Hold) */
    IfxGtm_Tim_In_ConfigFilterMode_none                           /**< \brief No filter */
} IfxGtm_Tim_In_ConfigFilterMode;

/** \brief Input Source
 */
typedef enum
{
    IfxGtm_Tim_In_Input_currentChannel,   /**< \brief Use the input from the current channel */
    IfxGtm_Tim_In_Input_adjacentChannel,  /**< \brief Use the input from the adjacent channel */
    IfxGtm_Tim_In_Input_aux               /**< \brief Use the input from the aux */
} IfxGtm_Tim_In_Input;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Tim_In_DataStructures
 * \{ */
/** \brief Configuration structure for TIM capture
 */
typedef struct
{
    boolean        irqOnNewVal;             /**< \brief If TRUE, the interrupt on new value is enabled */
    boolean        irqOnCntOverflow;        /**< \brief If TRUE, the interrupt on CNT overflow is enabled */
    boolean        irqOnEcntOverflow;       /**< \brief If TRUE, the interrupt on ECNT (Edge counter) overflow is enabled */
    boolean        irqOnDatalost;           /**< \brief If TRUE, the interrupt on data lost (GPR0, GPR1) is enabled */
    IfxGtm_Cmu_Clk clock;                   /**< \brief Timer input clock */
    Ifx_Pwm_Mode   mode;                    /**< \brief PWM mode, only Ifx_Pwm_Mode_leftAligned and Ifx_Pwm_Mode_righAligned are supported */
} IfxGtm_Tim_In_ConfigCapture;

/** \brief Configuration structure for TIM filter
 */
typedef struct
{
    IfxGtm_Cmu_Tim_Filter_Clk      clock;                       /**< \brief Timeout clock */
    IfxGtm_Tim_In_ConfigFilterMode risingEdgeMode;              /**< \brief Filter mode for rising edge */
    IfxGtm_Tim_In_ConfigFilterMode fallingEdgeMode;             /**< \brief Filter mode for falling edge */
    float32                        risingEdgeFilterTime;        /**< \brief Rising edge filter time  in second */
    float32                        fallingEdgeFilterTime;       /**< \brief Falling edge filter time in second */
    boolean                        irqOnGlitch;                 /**< \brief If TRUE, the interrupt on glitch is enabled */
    IfxGtm_Tim_In_Input            input;                       /**< \brief selected input */
    IfxGtm_Tim_TinMap             *inputPin;                    /**< \brief If defined, this value overwrites the IfxGtm_Tim_In_Config.filter.input, IfxGtm_Tim_In_Config.timIndex, IfxGtm_Tim_In_Config.channelIndex */
    IfxPort_InputMode              inputPinMode;                /**< \brief Input pin mode */
} IfxGtm_Tim_In_ConfigFilter;

/** \brief Configuration structure for TIM timeout
 */
typedef struct
{
    IfxGtm_Cmu_Clk clock;              /**< \brief Timeout clock */
    float32        timeout;            /**< \brief Timeout in second. Value of 0 disable the timeout functionality FIXME see 27.10.3 Timeout Detection Unit (TDU) */
    boolean        irqOnTimeout;       /**< \brief If TRUE, the interrupt on timeout is enabled */
} IfxGtm_Tim_In_ConfigTimeout;

/** \} */

/** \addtogroup IfxLld_Gtm_Tim_In_DataStructures
 * \{ */
/** \brief Driver Handle
 */
typedef struct
{
    Ifx_GTM_TIM_CH *channel;                     /**< \brief TIM channel used */
    uint32          periodTick;                  /**< \brief Period value in clock ticks */
    uint32          pulseLengthTick;             /**< \brief Duty value in clock ticks */
    boolean         dataCoherent;                /**< \brief TRUE, if the duty and period values are measured from the same period */
    boolean         overflowCnt;                 /**< \brief TRUE if the last measurement show an overflow in CNT */
    boolean         newData;                     /**< \brief TRUE when values are updated, and  if none of the counter CNT, CNTS have overflowed */
    boolean         dataLost;                    /**< \brief TRUE if data are lost */
    uint32          edgeCounterUpper;            /**< \brief upper part of the edge counter */
    boolean         glitch;                      /**< \brief TRUE if glitch is detected */
    float32         captureClockFrequency;       /**< \brief Capture clock frequency in Hz */
    IfxGtm_Tim      timIndex;                    /**< \brief Index of the TIM module being used. */
    IfxGtm_Tim_Ch   channelIndex;                /**< \brief Index of the TIM channel being used. */
    uint16          edgeCount;                   /**< \brief number of edges counted. */
} IfxGtm_Tim_In;

/** \brief Configuration structure for TIM input capture
 */
typedef struct
{
    Ifx_GTM                    *gtm;                /**< \brief GTM used */
    IfxGtm_Tim                  timIndex;           /**< \brief TIM index */
    IfxGtm_Tim_Ch               channelIndex;       /**< \brief Channel index */
    IfxGtm_IrqMode              irqMode;            /**< \brief Interrupt mode for the new value available */
    IfxSrc_Tos                  isrProvider;        /**< \brief Interrupt service provider for the timer interrupt */
    Ifx_Priority                isrPriority;        /**< \brief Set the interrupt priority for new value available. If 0, no interrupt will be generated */
    IfxGtm_Tim_In_ConfigCapture capture;            /**< \brief Capture configuration */
    IfxGtm_Tim_In_ConfigFilter  filter;             /**< \brief Filter configuration */
    IfxGtm_Tim_In_ConfigTimeout timeout;            /**< \brief Timeout configuration */
} IfxGtm_Tim_In_Config;

/** \} */

/** \addtogroup IfxLld_Gtm_Tim_In_Funtions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clear the new data flag
 * \param driver TIM Input object
 * \return None
 */
IFX_INLINE void IfxGtm_Tim_In_clearNewData(IfxGtm_Tim_In *driver);

/** \brief return the dutycycle in percent
 * \param driver TIM Input object
 * \param dataCoherent If true, the duty cycle has been calculated with coherent values for the period and duty, else the period and duty value are from 2 adjacent periods
 * \return duty
 */
IFX_INLINE float32 IfxGtm_Tim_In_getDutyPercent(IfxGtm_Tim_In *driver, boolean *dataCoherent);

/** \brief Return the period in second
 * \param driver TIM Input object
 * \return period value in seconds
 */
IFX_INLINE float32 IfxGtm_Tim_In_getPeriodSecond(IfxGtm_Tim_In *driver);

/** \brief Return the period value in tick
 * \param driver TIM Input object
 * \return period value in ticks
 */
IFX_INLINE sint32 IfxGtm_Tim_In_getPeriodTicks(IfxGtm_Tim_In *driver);

/** \brief Return the pulse length value in tick
 * \param driver TIM Input object
 * \return pulse length
 */
IFX_INLINE sint32 IfxGtm_Tim_In_getPulseLengthTick(IfxGtm_Tim_In *driver);

/** \brief Indicates if data were lost
 * \param driver TIM Input object
 * \return TRUE if Data is lost FALSE otherwise
 */
IFX_INLINE boolean IfxGtm_Tim_In_isDataLost(IfxGtm_Tim_In *driver);

/** \brief Indicates if new data are present (new data flag)
 * \param driver TIM Input object
 * \return TRUE if New Data FALSE otherwise
 */
IFX_INLINE boolean IfxGtm_Tim_In_isNewData(IfxGtm_Tim_In *driver);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initializes the input capture object
 * \param driver TIM Input object
 * \param config Configuration structure for the input capture Timer
 * \return TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxGtm_Tim_In_init(IfxGtm_Tim_In *driver, const IfxGtm_Tim_In_Config *config);

/** \brief Initializes the configuration structure to default
 * \param config Configuration structure for the input capture Timer
 * \param gtm Pointer to GTM module
 * \return None
 */
IFX_EXTERN void IfxGtm_Tim_In_initConfig(IfxGtm_Tim_In_Config *config, Ifx_GTM *gtm);

/** \brief will update the  driver state\n
 * To be called in the interrupt generated by the IfxGtm_Tim_In driver
 * \param driver TIM Input object
 * \return None
 */
IFX_EXTERN void IfxGtm_Tim_In_onIsr(IfxGtm_Tim_In *driver);

/** \brief Updates the period and duty cycle
 * \param driver TIM Input object
 * \return None
 */
IFX_EXTERN void IfxGtm_Tim_In_update(IfxGtm_Tim_In *driver);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGtm_Tim_In_clearNewData(IfxGtm_Tim_In *driver)
{
    driver->newData = FALSE;
}


IFX_INLINE float32 IfxGtm_Tim_In_getDutyPercent(IfxGtm_Tim_In *driver, boolean *dataCoherent)
{
    float32 duty;
    boolean interruptState = IfxCpu_disableInterrupts();
    duty          = (float32)driver->periodTick / driver->pulseLengthTick;
    *dataCoherent = driver->dataCoherent;
    IfxCpu_restoreInterrupts(interruptState);

    return duty;
}


IFX_INLINE float32 IfxGtm_Tim_In_getPeriodSecond(IfxGtm_Tim_In *driver)
{
    return IfxGtm_Tim_In_getPeriodTicks(driver) / driver->captureClockFrequency;
}


IFX_INLINE sint32 IfxGtm_Tim_In_getPeriodTicks(IfxGtm_Tim_In *driver)
{
    return driver->periodTick;
}


IFX_INLINE sint32 IfxGtm_Tim_In_getPulseLengthTick(IfxGtm_Tim_In *driver)
{
    return driver->pulseLengthTick;
}


IFX_INLINE boolean IfxGtm_Tim_In_isDataLost(IfxGtm_Tim_In *driver)
{
    return driver->dataLost;
}


IFX_INLINE boolean IfxGtm_Tim_In_isNewData(IfxGtm_Tim_In *driver)
{
    return driver->newData;
}


#endif /* IFXGTM_TIM_IN_H */

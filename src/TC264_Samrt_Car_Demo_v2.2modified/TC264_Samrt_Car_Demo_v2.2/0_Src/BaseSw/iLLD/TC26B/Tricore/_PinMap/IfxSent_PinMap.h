/**
 * \file IfxSent_PinMap.h
 * \brief SENT I/O map
 * \ingroup IfxLld_Sent
 *
 * \version iLLD_1_0_1_7_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Sent_pinmap SENT Pin Mapping
 * \ingroup IfxLld_Sent
 */

#ifndef IFXSENT_PINMAP_H
#define IFXSENT_PINMAP_H

#include <IfxSent_reg.h>
#include <_Impl/IfxSent_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Sent_pinmap
 * \{ */

/** \brief SENT pin mapping structure */
typedef const struct
{
    Ifx_SENT*         module;    /**< \brief Base address */
    IfxSent_ChannelId channelId; /**< \brief Channel ID */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    Ifx_RxSel         select;    /**< \brief Input multiplexer value */
} IfxSent_Sent_In;

/** \brief SPC pin mapping structure */
typedef const struct
{
    Ifx_SENT*         module;    /**< \brief Base address */
    IfxSent_ChannelId channelId; /**< \brief Channel ID */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxSent_Spc_Out;

IFX_EXTERN IfxSent_Sent_In IfxSent_SENT0A_AN24_IN;  /**< \brief SENT_SENT0A: SENT input channel 0 pin A */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT0A_P40_0_IN;  /**< \brief SENT_SENT0A: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT0B_P00_1_IN;  /**< \brief SENT_SENT0B: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT0C_P02_8_IN;  /**< \brief SENT_SENT0C: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT1A_AN25_IN;  /**< \brief SENT_SENT1A: SENT input channel 1 pin A */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT1A_P40_1_IN;  /**< \brief SENT_SENT1A: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT1B_P00_2_IN;  /**< \brief SENT_SENT1B: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT1C_P02_7_IN;  /**< \brief SENT_SENT1C: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT2A_AN26_IN;  /**< \brief SENT_SENT2A: SENT input channel 2 pin A */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT2A_P40_2_IN;  /**< \brief SENT_SENT2A: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT2B_P00_3_IN;  /**< \brief SENT_SENT2B: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT2C_P02_6_IN;  /**< \brief SENT_SENT2C: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT2D_AN36_IN;  /**< \brief SENT_SENT2D: SENT input channel 2 pin D */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT2D_P40_6_IN;  /**< \brief SENT_SENT2D: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT3A_AN27_IN;  /**< \brief SENT_SENT3A: SENT input channel 3 pin A */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT3A_P40_3_IN;  /**< \brief SENT_SENT3A: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT3B_P00_4_IN;  /**< \brief SENT_SENT3B: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT3C_P02_5_IN;  /**< \brief SENT_SENT3C: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT3D_AN37_IN;  /**< \brief SENT_SENT3D: SENT input channel 3 pin D */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT3D_P40_7_IN;  /**< \brief SENT_SENT3D: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT4A_AN38_IN;  /**< \brief SENT_SENT4A: SENT input channel 4 pin A */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT4A_P40_8_IN;  /**< \brief SENT_SENT4A: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT4B_P00_5_IN;  /**< \brief SENT_SENT4B: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT4C_P33_6_IN;  /**< \brief SENT_SENT4C: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT5A_AN39_IN;  /**< \brief SENT_SENT5A: SENT input channel 5 pin A */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT5A_P40_9_IN;  /**< \brief SENT_SENT5A: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT5B_P00_6_IN;  /**< \brief SENT_SENT5B: SENT input */
IFX_EXTERN IfxSent_Sent_In IfxSent_SENT5C_P33_5_IN;  /**< \brief SENT_SENT5C: SENT input */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC0_P00_1_OUT;  /**< \brief SENT_SPC0: SENT output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC1_P02_7_OUT;  /**< \brief SENT_SPC1: SENT output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC2_P00_3_OUT;  /**< \brief SENT_SPC2: SENT output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC3_P00_4_OUT;  /**< \brief SENT_SPC3: SENT output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC4_P00_5_OUT;  /**< \brief SENT_SPC4: SENT output */
IFX_EXTERN IfxSent_Spc_Out IfxSent_SPC5_P00_6_OUT;  /**< \brief SENT_SPC5: SENT output */

/** \brief Table dimensions */
#define IFXSENT_PINMAP_NUM_MODULES 1
#define IFXSENT_PINMAP_NUM_CHANNELS 6
#define IFXSENT_PINMAP_SENT_IN_NUM_ITEMS 4
#define IFXSENT_PINMAP_SPC_OUT_NUM_ITEMS 1


/** \brief IfxSent_Sent_In table */
IFX_EXTERN const IfxSent_Sent_In *IfxSent_Sent_In_pinTable[IFXSENT_PINMAP_NUM_MODULES][IFXSENT_PINMAP_NUM_CHANNELS][IFXSENT_PINMAP_SENT_IN_NUM_ITEMS];

/** \brief IfxSent_Spc_Out table */
IFX_EXTERN const IfxSent_Spc_Out *IfxSent_Spc_Out_pinTable[IFXSENT_PINMAP_NUM_MODULES][IFXSENT_PINMAP_NUM_CHANNELS][IFXSENT_PINMAP_SPC_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXSENT_PINMAP_H */

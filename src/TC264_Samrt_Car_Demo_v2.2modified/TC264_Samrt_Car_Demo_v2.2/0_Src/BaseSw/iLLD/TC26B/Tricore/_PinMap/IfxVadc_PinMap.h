/**
 * \file IfxVadc_PinMap.h
 * \brief VADC I/O map
 * \ingroup IfxLld_Vadc
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
 * \defgroup IfxLld_Vadc_pinmap VADC Pin Mapping
 * \ingroup IfxLld_Vadc
 */

#ifndef IFXVADC_PINMAP_H
#define IFXVADC_PINMAP_H

#include <IfxVadc_reg.h>
#include <_Impl/IfxVadc_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Vadc_pinmap
 * \{ */

/** \brief VADC Boundary Flag pin mapping structure */
typedef const struct
{
    Ifx_VADC*         module;    /**< \brief Base address */
    IfxVadc_GroupId   groupId;   /**< \brief Group ID */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxVadc_GxBfl_Out;

/** \brief VADC External Mux pin mapping structure */
typedef const struct
{
    Ifx_VADC*         module;    /**< \brief Base address */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    IfxPort_OutputIdx select;    /**< \brief Port control code */
} IfxVadc_Emux_Out;

/** \brief VADC Analog Input */
typedef const struct
{
    Ifx_VADC*         module;    /**< \brief Base address */
    IfxVadc_GroupId   groupId;   /**< \brief Group ID */
    IfxPort_Pin       pin;       /**< \brief Port pin */
    uint8             channelId; /**< \brief Channel ID */
} IfxVadc_Vadcg_In;

IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX00_P02_6_OUT;  /**< \brief VADC_EMUX00: VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX00_P33_3_OUT;  /**< \brief VADC_EMUX00: VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX01_P02_7_OUT;  /**< \brief VADC_EMUX01: VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX01_P33_2_OUT;  /**< \brief VADC_EMUX01: VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX02_P02_8_OUT;  /**< \brief VADC_EMUX02: VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX02_P33_1_OUT;  /**< \brief VADC_EMUX02: VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX10_P00_6_OUT;  /**< \brief VADC_EMUX10: VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX10_P33_6_OUT;  /**< \brief VADC_EMUX10: VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX11_P00_7_OUT;  /**< \brief VADC_EMUX11: VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX11_P33_5_OUT;  /**< \brief VADC_EMUX11: VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX12_P00_8_OUT;  /**< \brief VADC_EMUX12: VADC output */
IFX_EXTERN IfxVadc_Emux_Out IfxVadc_EMUX12_P33_4_OUT;  /**< \brief VADC_EMUX12: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G0BFL0_P33_4_OUT;  /**< \brief VADC_G0BFL0: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G0BFL1_P33_5_OUT;  /**< \brief VADC_G0BFL1: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G0BFL2_P33_6_OUT;  /**< \brief VADC_G0BFL2: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G0BFL3_P33_7_OUT;  /**< \brief VADC_G0BFL3: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G1BFL0_P33_0_OUT;  /**< \brief VADC_G1BFL0: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G1BFL1_P33_1_OUT;  /**< \brief VADC_G1BFL1: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G1BFL2_P33_2_OUT;  /**< \brief VADC_G1BFL2: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G1BFL3_P33_3_OUT;  /**< \brief VADC_G1BFL3: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G2BFL0_P00_4_OUT;  /**< \brief VADC_G2BFL0: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G2BFL1_P00_5_OUT;  /**< \brief VADC_G2BFL1: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G2BFL2_P00_6_OUT;  /**< \brief VADC_G2BFL2: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G2BFL3_P00_7_OUT;  /**< \brief VADC_G2BFL3: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G3BFL0_P10_0_OUT;  /**< \brief VADC_G3BFL0: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G3BFL0_P10_6_OUT;  /**< \brief VADC_G3BFL0: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G3BFL1_P10_1_OUT;  /**< \brief VADC_G3BFL1: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G3BFL1_P10_7_OUT;  /**< \brief VADC_G3BFL1: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G3BFL2_P10_2_OUT;  /**< \brief VADC_G3BFL2: VADC output */
IFX_EXTERN IfxVadc_GxBfl_Out IfxVadc_G3BFL3_P10_3_OUT;  /**< \brief VADC_G3BFL3: VADC output */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_0_AN0_IN;  /**< \brief VADC_G0_0: VADC input channel 0 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_10_AN10_IN;  /**< \brief VADC_G0_10: VADC input channel 10 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_11_AN11_IN;  /**< \brief VADC_G0_11: VADC input channel 11 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_12_AN12_IN;  /**< \brief VADC_G0_12: VADC input channel 12 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_13_AN13_IN;  /**< \brief VADC_G0_13: VADC input channel 13 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_1_AN1_IN;  /**< \brief VADC_G0_1: VADC input channel 1 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_2_AN2_IN;  /**< \brief VADC_G0_2: VADC input channel 2 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_3_AN3_IN;  /**< \brief VADC_G0_3: VADC input channel 3 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_4_AN4_IN;  /**< \brief VADC_G0_4: VADC input channel 4 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_5_AN5_IN;  /**< \brief VADC_G0_5: VADC input channel 5 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_6_AN6_IN;  /**< \brief VADC_G0_6: VADC input channel 6 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_7_AN7_IN;  /**< \brief VADC_G0_7: VADC input channel 7 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G0_8_AN8_IN;  /**< \brief VADC_G0_8: VADC input channel 8 of group 0 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_0_AN16_IN;  /**< \brief VADC_G1_0: VADC input channel 0 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_10_AN26_IN;  /**< \brief VADC_G1_10: VADC input channel 10 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_10_P40_2_IN;  /**< \brief VADC_G1_10: VADC input channel 10 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_11_AN27_IN;  /**< \brief VADC_G1_11: VADC input channel 11 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_11_P40_3_IN;  /**< \brief VADC_G1_11: VADC input channel 11 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_12_AN28_IN;  /**< \brief VADC_G1_12: VADC input channel 12 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_13_AN29_IN;  /**< \brief VADC_G1_13: VADC input channel 13 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_1_AN17_IN;  /**< \brief VADC_G1_1: VADC input channel 1 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_2_AN18_IN;  /**< \brief VADC_G1_2: VADC input channel 2 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_3_AN19_IN;  /**< \brief VADC_G1_3: VADC input channel 3 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_4_AN20_IN;  /**< \brief VADC_G1_4: VADC input channel 4 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_5_AN21_IN;  /**< \brief VADC_G1_5: VADC input channel 5 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_8_AN24_IN;  /**< \brief VADC_G1_8: VADC input channel 8 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_8_P40_0_IN;  /**< \brief VADC_G1_8: VADC input channel 8 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_9_AN25_IN;  /**< \brief VADC_G1_9: VADC input channel 9of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G1_9_P40_1_IN;  /**< \brief VADC_G1_9: VADC input channel 9 of group 1 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_0_AN32_IN;  /**< \brief VADC_G2_0: VADC input channel 0 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_10_AN44_IN;  /**< \brief VADC_G2_10: VADC input channel 10 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_11_AN45_IN;  /**< \brief VADC_G2_11: VADC input channel 11 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_12_AN46_IN;  /**< \brief VADC_G2_12: VADC input channel 12 of group 24 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_13_AN47_IN;  /**< \brief VADC_G2_13: VADC input channel 13 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_14_AN48_IN;  /**< \brief VADC_G2_14: VADC input channel 14 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_15_AN49_IN;  /**< \brief VADC_G2_15: VADC input channel 15 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_1_AN33_IN;  /**< \brief VADC_G2_1: VADC input channel 1 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_3_AN35_IN;  /**< \brief VADC_G2_3: VADC input channel 3 of group 2 (mtm) */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_4_AN36_IN;  /**< \brief VADC_G2_4: VADC input channel 4 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_4_P40_6_IN;  /**< \brief VADC_G2_4: VADC input channel 4 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_5_AN37_IN;  /**< \brief VADC_G2_5: VADC input channel 5 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_5_P40_7_IN;  /**< \brief VADC_G2_5: VADC input channel 5 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_6_AN38_IN;  /**< \brief VADC_G2_6: VADC input channel 6 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_6_P40_8_IN;  /**< \brief VADC_G2_6: VADC input channel 6 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_7_AN39_IN;  /**< \brief VADC_G2_7: VADC input channel 7 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G2_7_P40_9_IN;  /**< \brief VADC_G2_7: VADC input channel 7 of group 2 */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G3_0_P00_12_IN;  /**< \brief VADC_G3_0: VADC input */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G3_10_P00_2_IN;  /**< \brief VADC_G3_10: VADC input */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G3_11_P00_1_IN;  /**< \brief VADC_G3_11: VADC input */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G3_1_P00_11_IN;  /**< \brief VADC_G3_1: VADC input */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G3_2_P00_10_IN;  /**< \brief VADC_G3_2: VADC input */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G3_3_P00_9_IN;  /**< \brief VADC_G3_3: VADC input */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G3_4_P00_8_IN;  /**< \brief VADC_G3_4: VADC input */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G3_5_P00_7_IN;  /**< \brief VADC_G3_5: VADC input */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G3_6_P00_6_IN;  /**< \brief VADC_G3_6: VADC input */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G3_7_P00_5_IN;  /**< \brief VADC_G3_7: VADC input */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G3_8_P00_4_IN;  /**< \brief VADC_G3_8: VADC input */
IFX_EXTERN IfxVadc_Vadcg_In IfxVadc_G3_9_P00_3_IN;  /**< \brief VADC_G3_9: VADC input */

/** \brief Table dimensions */
#define IFXVADC_PINMAP_NUM_MODULES 1
#define IFXVADC_PINMAP_NUM_GROUPS 4
#define IFXVADC_PINMAP_EMUX_OUT_NUM_ITEMS 12
#define IFXVADC_PINMAP_GXBFL_OUT_NUM_ITEMS 6
#define IFXVADC_PINMAP_VADCG_IN_NUM_ITEMS 16


/** \brief IfxVadc_Emux_Out table */
IFX_EXTERN const IfxVadc_Emux_Out *IfxVadc_Emux_Out_pinTable[IFXVADC_PINMAP_NUM_MODULES][IFXVADC_PINMAP_EMUX_OUT_NUM_ITEMS];

/** \brief IfxVadc_GxBfl_Out table */
IFX_EXTERN const IfxVadc_GxBfl_Out *IfxVadc_GxBfl_Out_pinTable[IFXVADC_PINMAP_NUM_MODULES][IFXVADC_PINMAP_NUM_GROUPS][IFXVADC_PINMAP_GXBFL_OUT_NUM_ITEMS];

/** \brief IfxVadc_Vadcg_In table */
IFX_EXTERN const IfxVadc_Vadcg_In *IfxVadc_Vadcg_In_pinTable[IFXVADC_PINMAP_NUM_MODULES][IFXVADC_PINMAP_NUM_GROUPS][IFXVADC_PINMAP_VADCG_IN_NUM_ITEMS];

/** \} */

#endif /* IFXVADC_PINMAP_H */

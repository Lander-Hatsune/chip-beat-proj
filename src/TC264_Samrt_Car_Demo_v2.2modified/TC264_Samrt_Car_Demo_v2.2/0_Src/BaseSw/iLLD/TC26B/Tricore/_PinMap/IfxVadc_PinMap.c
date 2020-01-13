/**
 * \file IfxVadc_PinMap.c
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
 */

#include "IfxVadc_PinMap.h"

IfxVadc_Emux_Out IfxVadc_EMUX00_P02_6_OUT = {&MODULE_VADC, {&MODULE_P02, 6}, IfxPort_OutputIdx_alt5};
IfxVadc_Emux_Out IfxVadc_EMUX00_P33_3_OUT = {&MODULE_VADC, {&MODULE_P33, 3}, IfxPort_OutputIdx_alt5};
IfxVadc_Emux_Out IfxVadc_EMUX01_P02_7_OUT = {&MODULE_VADC, {&MODULE_P02, 7}, IfxPort_OutputIdx_alt5};
IfxVadc_Emux_Out IfxVadc_EMUX01_P33_2_OUT = {&MODULE_VADC, {&MODULE_P33, 2}, IfxPort_OutputIdx_alt5};
IfxVadc_Emux_Out IfxVadc_EMUX02_P02_8_OUT = {&MODULE_VADC, {&MODULE_P02, 8}, IfxPort_OutputIdx_alt5};
IfxVadc_Emux_Out IfxVadc_EMUX02_P33_1_OUT = {&MODULE_VADC, {&MODULE_P33, 1}, IfxPort_OutputIdx_alt5};
IfxVadc_Emux_Out IfxVadc_EMUX10_P00_6_OUT = {&MODULE_VADC, {&MODULE_P00, 6}, IfxPort_OutputIdx_alt5};
IfxVadc_Emux_Out IfxVadc_EMUX10_P33_6_OUT = {&MODULE_VADC, {&MODULE_P33, 6}, IfxPort_OutputIdx_alt5};
IfxVadc_Emux_Out IfxVadc_EMUX11_P00_7_OUT = {&MODULE_VADC, {&MODULE_P00, 7}, IfxPort_OutputIdx_alt5};
IfxVadc_Emux_Out IfxVadc_EMUX11_P33_5_OUT = {&MODULE_VADC, {&MODULE_P33, 5}, IfxPort_OutputIdx_alt5};
IfxVadc_Emux_Out IfxVadc_EMUX12_P00_8_OUT = {&MODULE_VADC, {&MODULE_P00, 8}, IfxPort_OutputIdx_alt5};
IfxVadc_Emux_Out IfxVadc_EMUX12_P33_4_OUT = {&MODULE_VADC, {&MODULE_P33, 4}, IfxPort_OutputIdx_alt5};
IfxVadc_GxBfl_Out IfxVadc_G0BFL0_P33_4_OUT = {&MODULE_VADC, IfxVadc_GroupId_0, {&MODULE_P33, 4}, IfxPort_OutputIdx_alt6};
IfxVadc_GxBfl_Out IfxVadc_G0BFL1_P33_5_OUT = {&MODULE_VADC, IfxVadc_GroupId_0, {&MODULE_P33, 5}, IfxPort_OutputIdx_alt6};
IfxVadc_GxBfl_Out IfxVadc_G0BFL2_P33_6_OUT = {&MODULE_VADC, IfxVadc_GroupId_0, {&MODULE_P33, 6}, IfxPort_OutputIdx_alt6};
IfxVadc_GxBfl_Out IfxVadc_G0BFL3_P33_7_OUT = {&MODULE_VADC, IfxVadc_GroupId_0, {&MODULE_P33, 7}, IfxPort_OutputIdx_alt6};
IfxVadc_GxBfl_Out IfxVadc_G1BFL0_P33_0_OUT = {&MODULE_VADC, IfxVadc_GroupId_1, {&MODULE_P33, 0}, IfxPort_OutputIdx_alt6};
IfxVadc_GxBfl_Out IfxVadc_G1BFL1_P33_1_OUT = {&MODULE_VADC, IfxVadc_GroupId_1, {&MODULE_P33, 1}, IfxPort_OutputIdx_alt6};
IfxVadc_GxBfl_Out IfxVadc_G1BFL2_P33_2_OUT = {&MODULE_VADC, IfxVadc_GroupId_1, {&MODULE_P33, 2}, IfxPort_OutputIdx_alt6};
IfxVadc_GxBfl_Out IfxVadc_G1BFL3_P33_3_OUT = {&MODULE_VADC, IfxVadc_GroupId_1, {&MODULE_P33, 3}, IfxPort_OutputIdx_alt6};
IfxVadc_GxBfl_Out IfxVadc_G2BFL0_P00_4_OUT = {&MODULE_VADC, IfxVadc_GroupId_2, {&MODULE_P00, 4}, IfxPort_OutputIdx_alt5};
IfxVadc_GxBfl_Out IfxVadc_G2BFL1_P00_5_OUT = {&MODULE_VADC, IfxVadc_GroupId_2, {&MODULE_P00, 5}, IfxPort_OutputIdx_alt5};
IfxVadc_GxBfl_Out IfxVadc_G2BFL2_P00_6_OUT = {&MODULE_VADC, IfxVadc_GroupId_2, {&MODULE_P00, 6}, IfxPort_OutputIdx_alt3};
IfxVadc_GxBfl_Out IfxVadc_G2BFL3_P00_7_OUT = {&MODULE_VADC, IfxVadc_GroupId_2, {&MODULE_P00, 7}, IfxPort_OutputIdx_alt3};
IfxVadc_GxBfl_Out IfxVadc_G3BFL0_P10_0_OUT = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P10, 0}, IfxPort_OutputIdx_alt5};
IfxVadc_GxBfl_Out IfxVadc_G3BFL0_P10_6_OUT = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P10, 6}, IfxPort_OutputIdx_alt7};
IfxVadc_GxBfl_Out IfxVadc_G3BFL1_P10_1_OUT = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P10, 1}, IfxPort_OutputIdx_alt5};
IfxVadc_GxBfl_Out IfxVadc_G3BFL1_P10_7_OUT = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P10, 7}, IfxPort_OutputIdx_alt4};
IfxVadc_GxBfl_Out IfxVadc_G3BFL2_P10_2_OUT = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P10, 2}, IfxPort_OutputIdx_alt5};
IfxVadc_GxBfl_Out IfxVadc_G3BFL3_P10_3_OUT = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P10, 3}, IfxPort_OutputIdx_alt2};
IfxVadc_Vadcg_In IfxVadc_G0_0_AN0_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR, 0}, 0};
IfxVadc_Vadcg_In IfxVadc_G0_10_AN10_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR,10}, 10};
IfxVadc_Vadcg_In IfxVadc_G0_11_AN11_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR,11}, 11};
IfxVadc_Vadcg_In IfxVadc_G0_12_AN12_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR,12}, 12};
IfxVadc_Vadcg_In IfxVadc_G0_13_AN13_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR,13}, 13};
IfxVadc_Vadcg_In IfxVadc_G0_1_AN1_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR, 1}, 1};
IfxVadc_Vadcg_In IfxVadc_G0_2_AN2_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR, 2}, 2};
IfxVadc_Vadcg_In IfxVadc_G0_3_AN3_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR, 3}, 3};
IfxVadc_Vadcg_In IfxVadc_G0_4_AN4_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR, 4}, 4};
IfxVadc_Vadcg_In IfxVadc_G0_5_AN5_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR, 5}, 5};
IfxVadc_Vadcg_In IfxVadc_G0_6_AN6_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR, 6}, 6};
IfxVadc_Vadcg_In IfxVadc_G0_7_AN7_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR, 7}, 7};
IfxVadc_Vadcg_In IfxVadc_G0_8_AN8_IN = {&MODULE_VADC, IfxVadc_GroupId_0, {NULL_PTR, 8}, 8};
IfxVadc_Vadcg_In IfxVadc_G1_0_AN16_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {NULL_PTR,16}, 0};
IfxVadc_Vadcg_In IfxVadc_G1_10_AN26_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {NULL_PTR,26}, 10};
IfxVadc_Vadcg_In IfxVadc_G1_10_P40_2_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {&MODULE_P40, 2}, 10};
IfxVadc_Vadcg_In IfxVadc_G1_11_AN27_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {NULL_PTR,27}, 11};
IfxVadc_Vadcg_In IfxVadc_G1_11_P40_3_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {&MODULE_P40, 3}, 11};
IfxVadc_Vadcg_In IfxVadc_G1_12_AN28_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {NULL_PTR,28}, 12};
IfxVadc_Vadcg_In IfxVadc_G1_13_AN29_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {NULL_PTR,29}, 13};
IfxVadc_Vadcg_In IfxVadc_G1_1_AN17_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {NULL_PTR,17}, 1};
IfxVadc_Vadcg_In IfxVadc_G1_2_AN18_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {NULL_PTR,18}, 2};
IfxVadc_Vadcg_In IfxVadc_G1_3_AN19_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {NULL_PTR,19}, 3};
IfxVadc_Vadcg_In IfxVadc_G1_4_AN20_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {NULL_PTR,20}, 4};
IfxVadc_Vadcg_In IfxVadc_G1_5_AN21_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {NULL_PTR,21}, 5};
IfxVadc_Vadcg_In IfxVadc_G1_8_AN24_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {NULL_PTR,24}, 8};
IfxVadc_Vadcg_In IfxVadc_G1_8_P40_0_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {&MODULE_P40, 0}, 8};
IfxVadc_Vadcg_In IfxVadc_G1_9_AN25_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {NULL_PTR,25}, 9};
IfxVadc_Vadcg_In IfxVadc_G1_9_P40_1_IN = {&MODULE_VADC, IfxVadc_GroupId_1, {&MODULE_P40, 1}, 9};
IfxVadc_Vadcg_In IfxVadc_G2_0_AN32_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,32}, 0};
IfxVadc_Vadcg_In IfxVadc_G2_10_AN44_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,44}, 10};
IfxVadc_Vadcg_In IfxVadc_G2_11_AN45_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,45}, 11};
IfxVadc_Vadcg_In IfxVadc_G2_12_AN46_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,46}, 12};
IfxVadc_Vadcg_In IfxVadc_G2_13_AN47_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,47}, 13};
IfxVadc_Vadcg_In IfxVadc_G2_14_AN48_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,48}, 14};
IfxVadc_Vadcg_In IfxVadc_G2_15_AN49_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,49}, 15};
IfxVadc_Vadcg_In IfxVadc_G2_1_AN33_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,33}, 1};
IfxVadc_Vadcg_In IfxVadc_G2_3_AN35_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,35}, 3};
IfxVadc_Vadcg_In IfxVadc_G2_4_AN36_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,36}, 4};
IfxVadc_Vadcg_In IfxVadc_G2_4_P40_6_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {&MODULE_P40, 6}, 4};
IfxVadc_Vadcg_In IfxVadc_G2_5_AN37_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,37}, 5};
IfxVadc_Vadcg_In IfxVadc_G2_5_P40_7_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {&MODULE_P40, 7}, 5};
IfxVadc_Vadcg_In IfxVadc_G2_6_AN38_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,38}, 6};
IfxVadc_Vadcg_In IfxVadc_G2_6_P40_8_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {&MODULE_P40, 8}, 6};
IfxVadc_Vadcg_In IfxVadc_G2_7_AN39_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {NULL_PTR,39}, 7};
IfxVadc_Vadcg_In IfxVadc_G2_7_P40_9_IN = {&MODULE_VADC, IfxVadc_GroupId_2, {&MODULE_P40, 9}, 7};
IfxVadc_Vadcg_In IfxVadc_G3_0_P00_12_IN = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P00,12}, 0};
IfxVadc_Vadcg_In IfxVadc_G3_10_P00_2_IN = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P00, 2}, 10};
IfxVadc_Vadcg_In IfxVadc_G3_11_P00_1_IN = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P00, 1}, 11};
IfxVadc_Vadcg_In IfxVadc_G3_1_P00_11_IN = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P00,11}, 1};
IfxVadc_Vadcg_In IfxVadc_G3_2_P00_10_IN = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P00,10}, 2};
IfxVadc_Vadcg_In IfxVadc_G3_3_P00_9_IN = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P00, 9}, 3};
IfxVadc_Vadcg_In IfxVadc_G3_4_P00_8_IN = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P00, 8}, 4};
IfxVadc_Vadcg_In IfxVadc_G3_5_P00_7_IN = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P00, 7}, 5};
IfxVadc_Vadcg_In IfxVadc_G3_6_P00_6_IN = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P00, 6}, 6};
IfxVadc_Vadcg_In IfxVadc_G3_7_P00_5_IN = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P00, 5}, 7};
IfxVadc_Vadcg_In IfxVadc_G3_8_P00_4_IN = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P00, 4}, 8};
IfxVadc_Vadcg_In IfxVadc_G3_9_P00_3_IN = {&MODULE_VADC, IfxVadc_GroupId_3, {&MODULE_P00, 3}, 9};


const IfxVadc_Emux_Out *IfxVadc_Emux_Out_pinTable[IFXVADC_PINMAP_NUM_MODULES][IFXVADC_PINMAP_EMUX_OUT_NUM_ITEMS] = {
    {
        &IfxVadc_EMUX10_P00_6_OUT,
        &IfxVadc_EMUX11_P00_7_OUT,
        &IfxVadc_EMUX12_P00_8_OUT,
        &IfxVadc_EMUX00_P02_6_OUT,
        &IfxVadc_EMUX01_P02_7_OUT,
        &IfxVadc_EMUX02_P02_8_OUT,
        &IfxVadc_EMUX02_P33_1_OUT,
        &IfxVadc_EMUX01_P33_2_OUT,
        &IfxVadc_EMUX00_P33_3_OUT,
        &IfxVadc_EMUX12_P33_4_OUT,
        &IfxVadc_EMUX11_P33_5_OUT,
        &IfxVadc_EMUX10_P33_6_OUT
    }
};

const IfxVadc_GxBfl_Out *IfxVadc_GxBfl_Out_pinTable[IFXVADC_PINMAP_NUM_MODULES][IFXVADC_PINMAP_NUM_GROUPS][IFXVADC_PINMAP_GXBFL_OUT_NUM_ITEMS] = {
    {
        {
            &IfxVadc_G0BFL0_P33_4_OUT,
            &IfxVadc_G0BFL1_P33_5_OUT,
            &IfxVadc_G0BFL2_P33_6_OUT,
            &IfxVadc_G0BFL3_P33_7_OUT,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxVadc_G1BFL0_P33_0_OUT,
            &IfxVadc_G1BFL1_P33_1_OUT,
            &IfxVadc_G1BFL2_P33_2_OUT,
            &IfxVadc_G1BFL3_P33_3_OUT,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxVadc_G2BFL0_P00_4_OUT,
            &IfxVadc_G2BFL1_P00_5_OUT,
            &IfxVadc_G2BFL2_P00_6_OUT,
            &IfxVadc_G2BFL3_P00_7_OUT,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxVadc_G3BFL0_P10_0_OUT,
            &IfxVadc_G3BFL1_P10_1_OUT,
            &IfxVadc_G3BFL2_P10_2_OUT,
            &IfxVadc_G3BFL3_P10_3_OUT,
            &IfxVadc_G3BFL0_P10_6_OUT,
            &IfxVadc_G3BFL1_P10_7_OUT
        }
    }
};

const IfxVadc_Vadcg_In *IfxVadc_Vadcg_In_pinTable[IFXVADC_PINMAP_NUM_MODULES][IFXVADC_PINMAP_NUM_GROUPS][IFXVADC_PINMAP_VADCG_IN_NUM_ITEMS] = {
    {
        {
            &IfxVadc_G0_0_AN0_IN,
            &IfxVadc_G0_1_AN1_IN,
            &IfxVadc_G0_2_AN2_IN,
            &IfxVadc_G0_3_AN3_IN,
            &IfxVadc_G0_4_AN4_IN,
            &IfxVadc_G0_5_AN5_IN,
            &IfxVadc_G0_6_AN6_IN,
            &IfxVadc_G0_7_AN7_IN,
            &IfxVadc_G0_8_AN8_IN,
            NULL_PTR,
            &IfxVadc_G0_10_AN10_IN,
            &IfxVadc_G0_11_AN11_IN,
            &IfxVadc_G0_12_AN12_IN,
            &IfxVadc_G0_13_AN13_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxVadc_G1_0_AN16_IN,
            &IfxVadc_G1_1_AN17_IN,
            &IfxVadc_G1_2_AN18_IN,
            &IfxVadc_G1_3_AN19_IN,
            &IfxVadc_G1_4_AN20_IN,
            &IfxVadc_G1_5_AN21_IN,
            NULL_PTR,
            NULL_PTR,
            &IfxVadc_G1_8_P40_0_IN,
            &IfxVadc_G1_9_P40_1_IN,
            &IfxVadc_G1_10_P40_2_IN,
            &IfxVadc_G1_11_P40_3_IN,
            &IfxVadc_G1_12_AN28_IN,
            &IfxVadc_G1_13_AN29_IN,
            NULL_PTR,
            NULL_PTR
        },
        {
            &IfxVadc_G2_0_AN32_IN,
            &IfxVadc_G2_1_AN33_IN,
            NULL_PTR,
            &IfxVadc_G2_3_AN35_IN,
            &IfxVadc_G2_4_P40_6_IN,
            &IfxVadc_G2_5_P40_7_IN,
            &IfxVadc_G2_6_P40_8_IN,
            &IfxVadc_G2_7_P40_9_IN,
            NULL_PTR,
            NULL_PTR,
            &IfxVadc_G2_10_AN44_IN,
            &IfxVadc_G2_11_AN45_IN,
            &IfxVadc_G2_12_AN46_IN,
            &IfxVadc_G2_13_AN47_IN,
            &IfxVadc_G2_14_AN48_IN,
            &IfxVadc_G2_15_AN49_IN
        },
        {
            &IfxVadc_G3_0_P00_12_IN,
            &IfxVadc_G3_1_P00_11_IN,
            &IfxVadc_G3_2_P00_10_IN,
            &IfxVadc_G3_3_P00_9_IN,
            &IfxVadc_G3_4_P00_8_IN,
            &IfxVadc_G3_5_P00_7_IN,
            &IfxVadc_G3_6_P00_6_IN,
            &IfxVadc_G3_7_P00_5_IN,
            &IfxVadc_G3_8_P00_4_IN,
            &IfxVadc_G3_9_P00_3_IN,
            &IfxVadc_G3_10_P00_2_IN,
            &IfxVadc_G3_11_P00_1_IN,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        }
    }
};

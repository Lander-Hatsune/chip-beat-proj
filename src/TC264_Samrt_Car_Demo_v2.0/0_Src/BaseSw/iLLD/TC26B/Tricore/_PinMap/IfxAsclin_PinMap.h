/**
 * \file IfxAsclin_PinMap.h
 * \brief ASCLIN I/O map
 * \ingroup IfxLld_Asclin
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
 * \defgroup IfxLld_Asclin_pinmap ASCLIN Pin Mapping
 * \ingroup IfxLld_Asclin
 */

#ifndef IFXASCLIN_PINMAP_H
#define IFXASCLIN_PINMAP_H

#include <IfxAsclin_reg.h>
#include <_Impl/IfxAsclin_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Asclin_pinmap
 * \{ */

/** \brief CTS pin mapping structure */
typedef const struct
{
    Ifx_ASCLIN*       module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxAsclin_Cts_In;

/** \brief RX pin mapping structure */
typedef const struct
{
    Ifx_ASCLIN*       module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxAsclin_Rx_In;

/** \brief RTS pin mapping structure */
typedef const struct
{
    Ifx_ASCLIN*       module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxAsclin_Rts_Out;

/** \brief SCLK pin mapping structure */
typedef const struct
{
    Ifx_ASCLIN*       module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxAsclin_Sclk_Out;

/** \brief SLSO pin mapping structure */
typedef const struct
{
    Ifx_ASCLIN*       module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxAsclin_Slso_Out;

/** \brief TX pin mapping structure */
typedef const struct
{
    Ifx_ASCLIN*       module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxAsclin_Tx_Out;

IFX_EXTERN IfxAsclin_Cts_In IfxAsclin0_CTSA_P14_9_IN;  /**< \brief ASCLIN0_CTSA: ASCLIN0 input */
IFX_EXTERN IfxAsclin_Cts_In IfxAsclin1_CTSA_P20_7_IN;  /**< \brief ASCLIN1_CTSA: ASCLIN1 input */
IFX_EXTERN IfxAsclin_Cts_In IfxAsclin1_CTSB_P32_4_IN;  /**< \brief ASCLIN1_CTSB: ASCLIN1 input */
IFX_EXTERN IfxAsclin_Cts_In IfxAsclin2_CTSA_P10_7_IN;  /**< \brief ASCLIN2_CTSA: ASCLIN2 input */
IFX_EXTERN IfxAsclin_Cts_In IfxAsclin2_CTSB_P33_5_IN;  /**< \brief ASCLIN2_CTSB: ASCLIN2 input */
IFX_EXTERN IfxAsclin_Cts_In IfxAsclin3_CTSA_P00_12_IN;  /**< \brief ASCLIN3_CTSA: ASCLIN3 input */
IFX_EXTERN IfxAsclin_Rts_Out IfxAsclin0_RTS_P14_7_OUT;  /**< \brief ASCLIN0_RTS: ASCLIN0 output */
IFX_EXTERN IfxAsclin_Rts_Out IfxAsclin1_RTS_P20_6_OUT;  /**< \brief ASCLIN1_RTS: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Rts_Out IfxAsclin1_RTS_P23_1_OUT;  /**< \brief ASCLIN1_RTS: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Rts_Out IfxAsclin2_RTS_P10_8_OUT;  /**< \brief ASCLIN2_RTS: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Rts_Out IfxAsclin2_RTS_P33_4_OUT;  /**< \brief ASCLIN2_RTS: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Rts_Out IfxAsclin3_RTS_P00_9_OUT;  /**< \brief ASCLIN3_RTS: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin0_RXA_P14_1_IN;  /**< \brief ASCLIN0_RXA: ASCLIN0 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin0_RXB_P15_3_IN;  /**< \brief ASCLIN0_RXB: ASCLIN0 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin1_RXA_P15_1_IN;  /**< \brief ASCLIN1_RXA: ASCLIN1 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin1_RXB_P15_5_IN;  /**< \brief ASCLIN1_RXB: ASCLIN1 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin1_RXC_P20_9_IN;  /**< \brief ASCLIN1_RXC: ASCLIN1 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin1_RXD_P14_8_IN;  /**< \brief ASCLIN1_RXD: ASCLIN1 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin1_RXE_P11_10_IN;  /**< \brief ASCLIN1_RXE: ASCLIN1 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin1_RXF_P33_13_IN;  /**< \brief ASCLIN1_RXF: ASCLIN1 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin1_RXG_P02_3_IN;  /**< \brief ASCLIN1_RXG: ASCLIN1 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin2_RXA_P14_3_IN;  /**< \brief ASCLIN2_RXA: ASCLIN2 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin2_RXB_P02_1_IN;  /**< \brief ASCLIN2_RXB: ASCLIN2 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin2_RXD_P10_6_IN;  /**< \brief ASCLIN2_RXD: ASCLIN2 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin2_RXE_P33_8_IN;  /**< \brief ASCLIN2_RXE: ASCLIN2 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin2_RXG_P02_0_IN;  /**< \brief ASCLIN2_RXG: ASCLIN2 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin3_RXA_P15_7_IN;  /**< \brief ASCLIN3_RXA: ASCLIN3 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin3_RXC_P20_3_IN;  /**< \brief ASCLIN3_RXC: ASCLIN3 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin3_RXD_P32_2_IN;  /**< \brief ASCLIN3_RXD: ASCLIN3 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin3_RXE_P00_1_IN;  /**< \brief ASCLIN3_RXE: ASCLIN3 input */
IFX_EXTERN IfxAsclin_Rx_In IfxAsclin3_RXF_P21_6_IN;  /**< \brief ASCLIN3_RXF: ASCLIN3 input */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin0_SCLK_P14_0_OUT;  /**< \brief ASCLIN0_SCLK: ASCLIN0 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin0_SCLK_P15_2_OUT;  /**< \brief ASCLIN0_SCLK: ASCLIN0 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin1_SCLK_P15_0_OUT;  /**< \brief ASCLIN1_SCLK: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin1_SCLK_P20_10_OUT;  /**< \brief ASCLIN1_SCLK: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin1_SCLK_P33_11_OUT;  /**< \brief ASCLIN1_SCLK: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin1_SCLK_P33_12_OUT;  /**< \brief ASCLIN1_SCLK: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin2_SCLK_P02_4_OUT;  /**< \brief ASCLIN2_SCLK: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin2_SCLK_P10_6_OUT;  /**< \brief ASCLIN2_SCLK: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin2_SCLK_P14_2_OUT;  /**< \brief ASCLIN2_SCLK: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin2_SCLK_P33_7_OUT;  /**< \brief ASCLIN2_SCLK: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin2_SCLK_P33_9_OUT;  /**< \brief ASCLIN2_SCLK: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin3_SCLK_P00_0_OUT;  /**< \brief ASCLIN3_SCLK: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin3_SCLK_P00_2_OUT;  /**< \brief ASCLIN3_SCLK: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin3_SCLK_P15_6_OUT;  /**< \brief ASCLIN3_SCLK: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin3_SCLK_P15_8_OUT;  /**< \brief ASCLIN3_SCLK: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin3_SCLK_P20_0_OUT;  /**< \brief ASCLIN3_SCLK: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin3_SCLK_P21_5_OUT;  /**< \brief ASCLIN3_SCLK: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin3_SCLK_P21_7_OUT;  /**< \brief ASCLIN3_SCLK: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin3_SCLK_P32_3_OUT;  /**< \brief ASCLIN3_SCLK: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Sclk_Out IfxAsclin3_SCLK_P33_2_OUT;  /**< \brief ASCLIN3_SCLK: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Slso_Out IfxAsclin1_SLSO_P14_3_OUT;  /**< \brief ASCLIN1_SLSO: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Slso_Out IfxAsclin1_SLSO_P20_8_OUT;  /**< \brief ASCLIN1_SLSO: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Slso_Out IfxAsclin1_SLSO_P33_10_OUT;  /**< \brief ASCLIN1_SLSO: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Slso_Out IfxAsclin2_SLSO_P02_3_OUT;  /**< \brief ASCLIN2_SLSO: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Slso_Out IfxAsclin2_SLSO_P10_5_OUT;  /**< \brief ASCLIN2_SLSO: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Slso_Out IfxAsclin2_SLSO_P33_6_OUT;  /**< \brief ASCLIN2_SLSO: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Slso_Out IfxAsclin3_SLSO_P00_3_OUT;  /**< \brief ASCLIN3_SLSO: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Slso_Out IfxAsclin3_SLSO_P14_3_OUT;  /**< \brief ASCLIN3_SLSO: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Slso_Out IfxAsclin3_SLSO_P21_2_OUT;  /**< \brief ASCLIN3_SLSO: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Slso_Out IfxAsclin3_SLSO_P21_6_OUT;  /**< \brief ASCLIN3_SLSO: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Slso_Out IfxAsclin3_SLSO_P33_1_OUT;  /**< \brief ASCLIN3_SLSO: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin0_TX_P14_0_OUT;  /**< \brief ASCLIN0_TX: ASCLIN0 output   Recommended as Boot loader pin. */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin0_TX_P14_1_OUT;  /**< \brief ASCLIN0_TX: ASCLIN0 output   Recommended as Boot loader pin. */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin0_TX_P15_2_OUT;  /**< \brief ASCLIN0_TX: ASCLIN0 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin0_TX_P15_3_OUT;  /**< \brief ASCLIN0_TX: ASCLIN0 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin1_TX_P02_2_OUT;  /**< \brief ASCLIN1_TX: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin1_TX_P11_12_OUT;  /**< \brief ASCLIN1_TX: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin1_TX_P14_10_OUT;  /**< \brief ASCLIN1_TX: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin1_TX_P15_0_OUT;  /**< \brief ASCLIN1_TX: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin1_TX_P15_1_OUT;  /**< \brief ASCLIN1_TX: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin1_TX_P15_4_OUT;  /**< \brief ASCLIN1_TX: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin1_TX_P15_5_OUT;  /**< \brief ASCLIN1_TX: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin1_TX_P20_10_OUT;  /**< \brief ASCLIN1_TX: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin1_TX_P33_12_OUT;  /**< \brief ASCLIN1_TX: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin1_TX_P33_13_OUT;  /**< \brief ASCLIN1_TX: ASCLIN1 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin2_TX_P02_0_OUT;  /**< \brief ASCLIN2_TX: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin2_TX_P10_5_OUT;  /**< \brief ASCLIN2_TX: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin2_TX_P14_2_OUT;  /**< \brief ASCLIN2_TX: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin2_TX_P14_3_OUT;  /**< \brief ASCLIN2_TX: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin2_TX_P33_8_OUT;  /**< \brief ASCLIN2_TX: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin2_TX_P33_9_OUT;  /**< \brief ASCLIN2_TX: ASCLIN2 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin3_TX_P00_0_OUT;  /**< \brief ASCLIN3_TX: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin3_TX_P00_1_OUT;  /**< \brief ASCLIN3_TX: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin3_TX_P15_6_OUT;  /**< \brief ASCLIN3_TX: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin3_TX_P15_7_OUT;  /**< \brief ASCLIN3_TX: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin3_TX_P20_0_OUT;  /**< \brief ASCLIN3_TX: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin3_TX_P20_3_OUT;  /**< \brief ASCLIN3_TX: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin3_TX_P21_7_OUT;  /**< \brief ASCLIN3_TX: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin3_TX_P32_2_OUT;  /**< \brief ASCLIN3_TX: ASCLIN3 output */
IFX_EXTERN IfxAsclin_Tx_Out IfxAsclin3_TX_P32_3_OUT;  /**< \brief ASCLIN3_TX: ASCLIN3 output */

/** \brief Table dimensions */
#define IFXASCLIN_PINMAP_NUM_MODULES 4
#define IFXASCLIN_PINMAP_CTS_IN_NUM_ITEMS 2
#define IFXASCLIN_PINMAP_RTS_OUT_NUM_ITEMS 2
#define IFXASCLIN_PINMAP_RX_IN_NUM_ITEMS 7
#define IFXASCLIN_PINMAP_SCLK_OUT_NUM_ITEMS 9
#define IFXASCLIN_PINMAP_SLSO_OUT_NUM_ITEMS 5
#define IFXASCLIN_PINMAP_TX_OUT_NUM_ITEMS 10


/** \brief IfxAsclin_Cts_In table */
IFX_EXTERN const IfxAsclin_Cts_In *IfxAsclin_Cts_In_pinTable[IFXASCLIN_PINMAP_NUM_MODULES][IFXASCLIN_PINMAP_CTS_IN_NUM_ITEMS];

/** \brief IfxAsclin_Rts_Out table */
IFX_EXTERN const IfxAsclin_Rts_Out *IfxAsclin_Rts_Out_pinTable[IFXASCLIN_PINMAP_NUM_MODULES][IFXASCLIN_PINMAP_RTS_OUT_NUM_ITEMS];

/** \brief IfxAsclin_Rx_In table */
IFX_EXTERN const IfxAsclin_Rx_In *IfxAsclin_Rx_In_pinTable[IFXASCLIN_PINMAP_NUM_MODULES][IFXASCLIN_PINMAP_RX_IN_NUM_ITEMS];

/** \brief IfxAsclin_Sclk_Out table */
IFX_EXTERN const IfxAsclin_Sclk_Out *IfxAsclin_Sclk_Out_pinTable[IFXASCLIN_PINMAP_NUM_MODULES][IFXASCLIN_PINMAP_SCLK_OUT_NUM_ITEMS];

/** \brief IfxAsclin_Slso_Out table */
IFX_EXTERN const IfxAsclin_Slso_Out *IfxAsclin_Slso_Out_pinTable[IFXASCLIN_PINMAP_NUM_MODULES][IFXASCLIN_PINMAP_SLSO_OUT_NUM_ITEMS];

/** \brief IfxAsclin_Tx_Out table */
IFX_EXTERN const IfxAsclin_Tx_Out *IfxAsclin_Tx_Out_pinTable[IFXASCLIN_PINMAP_NUM_MODULES][IFXASCLIN_PINMAP_TX_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXASCLIN_PINMAP_H */

/**
 * \file IfxEth_PinMap.h
 * \brief ETH I/O map
 * \ingroup IfxLld_Eth
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
 * \defgroup IfxLld_Eth_pinmap ETH Pin Mapping
 * \ingroup IfxLld_Eth
 */

#ifndef IFXETH_PINMAP_H
#define IFXETH_PINMAP_H

#include <IfxEth_reg.h>
#include <_Impl/IfxEth_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Eth_pinmap
 * \{ */

/** \brief CRS pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Crs_In;

/** \brief CRSDV pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Crsdv_In;

/** \brief RXDV pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Rxdv_In;

/** \brief REFCLK pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Refclk_In;

/** \brief RXCLK pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Rxclk_In;

/** \brief TXCLK pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Txclk_In;

/** \brief RXD pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Rxd_In;

/** \brief COL pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Col_In;

/** \brief MDC pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxEth_Mdc_Out;

/** \brief MDIO pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         inSelect; /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;/**< \brief Port control code */
} IfxEth_Mdio_InOut;

/** \brief TXD pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxEth_Txd_Out;

/** \brief TXEN pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxEth_Txen_Out;

/** \brief TXER pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxEth_Txer_Out;

/** \brief RXER pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Rxer_In;

IFX_EXTERN IfxEth_Crsdv_In IfxEth_CRSDVA_P11_11_IN;  /**< \brief ETH_CRSDVA: ETH input */
IFX_EXTERN IfxEth_Mdc_Out IfxEth_MDC_P02_8_OUT;  /**< \brief ETH_MDC: ETH output */
IFX_EXTERN IfxEth_Mdc_Out IfxEth_MDC_P21_0_OUT;  /**< \brief ETH_MDC: ETH output */
IFX_EXTERN IfxEth_Mdc_Out IfxEth_MDC_P21_2_OUT;  /**< \brief ETH_MDC: ETH output */
IFX_EXTERN IfxEth_Mdio_InOut IfxEth_MDIOA_P00_0_INOUT;  /**< \brief ETH_MDIOA: ETH input/output */
IFX_EXTERN IfxEth_Mdio_InOut IfxEth_MDIOD_P21_3_INOUT;  /**< \brief ETH_MDIOD: ETH input/output */
IFX_EXTERN IfxEth_Mdio_InOut IfxEth_MDIO_P21_1_INOUT;  /**< \brief ETH_MDIO: ETH output   (Not for production purposes) */
IFX_EXTERN IfxEth_Refclk_In IfxEth_REFCLK_P11_12_IN;  /**< \brief ETH_REFCLK: ETH input */
IFX_EXTERN IfxEth_Rxclk_In IfxEth_RXCLKA_P11_12_IN;  /**< \brief ETH_RXCLKA: ETH input   (Not for productive purposes) */
IFX_EXTERN IfxEth_Rxd_In IfxEth_RXD0_P11_10_IN;  /**< \brief ETH_RXD0: ETH input */
IFX_EXTERN IfxEth_Rxd_In IfxEth_RXD1_P11_9_IN;  /**< \brief ETH_RXD1: ETH input */
IFX_EXTERN IfxEth_Rxer_In IfxEth_RXERB_P21_7_IN;  /**< \brief ETH_RXERB: ETH input */
IFX_EXTERN IfxEth_Txclk_In IfxEth_TXCLKB_P11_12_IN;  /**< \brief ETH_TXCLKB: ETH input   (Not for productive purposes) */
IFX_EXTERN IfxEth_Txd_Out IfxEth_TXD0_P11_3_OUT;  /**< \brief ETH_TXD0: ETH output */
IFX_EXTERN IfxEth_Txd_Out IfxEth_TXD1_P11_2_OUT;  /**< \brief ETH_TXD1: ETH output */
IFX_EXTERN IfxEth_Txen_Out IfxEth_TXEN_P11_6_OUT;  /**< \brief ETH_TXEN: ETH output */

/** \brief Table dimensions */
#define IFXETH_PINMAP_NUM_MODULES 1
#define IFXETH_PINMAP_CRSDV_IN_NUM_ITEMS 1
#define IFXETH_PINMAP_MDC_OUT_NUM_ITEMS 3
#define IFXETH_PINMAP_MDIO_INOUT_NUM_ITEMS 7
#define IFXETH_PINMAP_REFCLK_IN_NUM_ITEMS 1
#define IFXETH_PINMAP_RXCLK_IN_NUM_ITEMS 1
#define IFXETH_PINMAP_RXD_IN_NUM_ITEMS 1
#define IFXETH_PINMAP_RXER_IN_NUM_ITEMS 2
#define IFXETH_PINMAP_TXCLK_IN_NUM_ITEMS 2
#define IFXETH_PINMAP_TXD_OUT_NUM_ITEMS 2
#define IFXETH_PINMAP_TXEN_OUT_NUM_ITEMS 1


/** \brief IfxEth_Crsdv_In table */
IFX_EXTERN const IfxEth_Crsdv_In *IfxEth_Crsdv_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_CRSDV_IN_NUM_ITEMS];

/** \brief IfxEth_Mdc_Out table */
IFX_EXTERN const IfxEth_Mdc_Out *IfxEth_Mdc_Out_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_MDC_OUT_NUM_ITEMS];

/** \brief IfxEth_Mdio_InOut table */
IFX_EXTERN const IfxEth_Mdio_InOut *IfxEth_Mdio_InOut_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_MDIO_INOUT_NUM_ITEMS];

/** \brief IfxEth_Refclk_In table */
IFX_EXTERN const IfxEth_Refclk_In *IfxEth_Refclk_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_REFCLK_IN_NUM_ITEMS];

/** \brief IfxEth_Rxclk_In table */
IFX_EXTERN const IfxEth_Rxclk_In *IfxEth_Rxclk_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_RXCLK_IN_NUM_ITEMS];

/** \brief IfxEth_Rxd_In table */
IFX_EXTERN const IfxEth_Rxd_In *IfxEth_Rxd_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_RXD_IN_NUM_ITEMS];

/** \brief IfxEth_Rxer_In table */
IFX_EXTERN const IfxEth_Rxer_In *IfxEth_Rxer_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_RXER_IN_NUM_ITEMS];

/** \brief IfxEth_Txclk_In table */
IFX_EXTERN const IfxEth_Txclk_In *IfxEth_Txclk_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_TXCLK_IN_NUM_ITEMS];

/** \brief IfxEth_Txd_Out table */
IFX_EXTERN const IfxEth_Txd_Out *IfxEth_Txd_Out_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_TXD_OUT_NUM_ITEMS];

/** \brief IfxEth_Txen_Out table */
IFX_EXTERN const IfxEth_Txen_Out *IfxEth_Txen_Out_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_TXEN_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXETH_PINMAP_H */

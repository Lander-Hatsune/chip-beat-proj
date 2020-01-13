/**
 * \file IfxDma_cfg.h
 * \brief DMA on-chip implementation data
 * \ingroup IfxLld_Dma
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
 * \defgroup IfxLld_Dma DMA
 * \ingroup IfxLld
 * \defgroup IfxLld_Dma_Impl Implementation
 * \ingroup IfxLld_Dma
 * \defgroup IfxLld_Dma_Std Standard Driver
 * \ingroup IfxLld_Dma
 */

#ifndef IFXDMA_CFG_H
#define IFXDMA_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of channels
 */
#define IFXDMA_NUM_CHANNELS 48

/** \brief Error mask for move engine source error
 */
#define IFXDMA_ERROR_S      (IFX_DMA_BLK_CLRE_CSER_MSK << IFX_DMA_BLK_CLRE_CSER_OFF)

/** \brief Error mask for move engine destination error
 */
#define IFXDMA_ERROR_D      (IFX_DMA_BLK_CLRE_CDER_MSK << IFX_DMA_BLK_CLRE_CDER_OFF)

/** \brief Error mask for bus error on SPB
 */
#define IFXDMA_ERROR_SPB    (IFX_DMA_BLK_CLRE_CSPBER_MSK << IFX_DMA_BLK_CLRE_CSPBER_OFF)

/** \brief Error mask for bus error on SRI
 */
#define IFXDMA_ERROR_SRI    (IFX_DMA_BLK_CLRE_CSRIER_MSK << IFX_DMA_BLK_CLRE_CSRIER_OFF)

/** \brief Error mask for RAM error
 */
#define IFXDMA_ERROR_RAM    (IFX_DMA_BLK_CLRE_CRAMER_MSK << IFX_DMA_BLK_CLRE_CRAMER_OFF)

/** \brief Error mask for SLL (safe linked list CRC checksum) error
 */
#define IFXDMA_ERROR_SLL    (IFX_DMA_BLK_CLRE_CSLLER_MSK << IFX_DMA_BLK_CLRE_CSLLER_OFF)

/** \brief Error mask for DLL (failed linked list load) error
 */
#define IFXDMA_ERROR_DLL    (IFX_DMA_BLK_CLRE_CDLLER_MSK << IFX_DMA_BLK_CLRE_CDLLER_OFF)

#define IFXDMA_NUM_MODULES  (1)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief DMA channel resources definition
 */
typedef enum
{
    IfxDma_ChannelId_none = -1,  /**< \brief None of the Ifx_DMA Channels */
    IfxDma_ChannelId_0    = 0,   /**< \brief Ifx_DMA Channel 0  */
    IfxDma_ChannelId_1,          /**< \brief Ifx_DMA Channel 1  */
    IfxDma_ChannelId_2,          /**< \brief Ifx_DMA Channel 2  */
    IfxDma_ChannelId_3,          /**< \brief Ifx_DMA Channel 3  */
    IfxDma_ChannelId_4,          /**< \brief Ifx_DMA Channel 4  */
    IfxDma_ChannelId_5,          /**< \brief Ifx_DMA Channel 5  */
    IfxDma_ChannelId_6,          /**< \brief Ifx_DMA Channel 6  */
    IfxDma_ChannelId_7,          /**< \brief Ifx_DMA Channel 7  */
    IfxDma_ChannelId_8,          /**< \brief Ifx_DMA Channel 8  */
    IfxDma_ChannelId_9,          /**< \brief Ifx_DMA Channel 9  */
    IfxDma_ChannelId_10,         /**< \brief Ifx_DMA Channel 10  */
    IfxDma_ChannelId_11,         /**< \brief Ifx_DMA Channel 11  */
    IfxDma_ChannelId_12,         /**< \brief Ifx_DMA Channel 12  */
    IfxDma_ChannelId_13,         /**< \brief Ifx_DMA Channel 13  */
    IfxDma_ChannelId_14,         /**< \brief Ifx_DMA Channel 14  */
    IfxDma_ChannelId_15,         /**< \brief Ifx_DMA Channel 15  */
    IfxDma_ChannelId_16,         /**< \brief Ifx_DMA Channel 16  */
    IfxDma_ChannelId_17,         /**< \brief Ifx_DMA Channel 17  */
    IfxDma_ChannelId_18,         /**< \brief Ifx_DMA Channel 18  */
    IfxDma_ChannelId_19,         /**< \brief Ifx_DMA Channel 19  */
    IfxDma_ChannelId_20,         /**< \brief Ifx_DMA Channel 20  */
    IfxDma_ChannelId_21,         /**< \brief Ifx_DMA Channel 21  */
    IfxDma_ChannelId_22,         /**< \brief Ifx_DMA Channel 22  */
    IfxDma_ChannelId_23,         /**< \brief Ifx_DMA Channel 23  */
    IfxDma_ChannelId_24,         /**< \brief Ifx_DMA Channel 24  */
    IfxDma_ChannelId_25,         /**< \brief Ifx_DMA Channel 25  */
    IfxDma_ChannelId_26,         /**< \brief Ifx_DMA Channel 26  */
    IfxDma_ChannelId_27,         /**< \brief Ifx_DMA Channel 27  */
    IfxDma_ChannelId_28,         /**< \brief Ifx_DMA Channel 28  */
    IfxDma_ChannelId_29,         /**< \brief Ifx_DMA Channel 29  */
    IfxDma_ChannelId_30,         /**< \brief Ifx_DMA Channel 30  */
    IfxDma_ChannelId_31,         /**< \brief Ifx_DMA Channel 31  */
    IfxDma_ChannelId_32,         /**< \brief Ifx_DMA Channel 32  */
    IfxDma_ChannelId_33,         /**< \brief Ifx_DMA Channel 33  */
    IfxDma_ChannelId_34,         /**< \brief Ifx_DMA Channel 34  */
    IfxDma_ChannelId_35,         /**< \brief Ifx_DMA Channel 35  */
    IfxDma_ChannelId_36,         /**< \brief Ifx_DMA Channel 36  */
    IfxDma_ChannelId_37,         /**< \brief Ifx_DMA Channel 37  */
    IfxDma_ChannelId_38,         /**< \brief Ifx_DMA Channel 38  */
    IfxDma_ChannelId_39,         /**< \brief Ifx_DMA Channel 39  */
    IfxDma_ChannelId_40,         /**< \brief Ifx_DMA Channel 40  */
    IfxDma_ChannelId_41,         /**< \brief Ifx_DMA Channel 41  */
    IfxDma_ChannelId_42,         /**< \brief Ifx_DMA Channel 42  */
    IfxDma_ChannelId_43,         /**< \brief Ifx_DMA Channel 43  */
    IfxDma_ChannelId_44,         /**< \brief Ifx_DMA Channel 44  */
    IfxDma_ChannelId_45,         /**< \brief Ifx_DMA Channel 45  */
    IfxDma_ChannelId_46,         /**< \brief Ifx_DMA Channel 46  */
    IfxDma_ChannelId_47          /**< \brief Ifx_DMA Channel 47  */
} IfxDma_ChannelId;

#endif /* IFXDMA_CFG_H */

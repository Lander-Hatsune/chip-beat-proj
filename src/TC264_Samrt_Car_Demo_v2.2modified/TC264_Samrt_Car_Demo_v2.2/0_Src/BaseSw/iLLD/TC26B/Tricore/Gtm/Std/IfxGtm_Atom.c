/**
 * \file IfxGtm_Atom.c
 * \brief GTM  basic functionality
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxGtm_Atom.h"
#include "IfxGtm_bf.h"

/******************************************************************************/
/*----------------------------------Macros------------------------------------*/
/******************************************************************************/

/** \brief Number of channels per ATOM AGC
 */
#define IFXGTM_ATOM_NUM_AGC_CHANNELS (8)

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

uint32 IfxGtm_Atom_Agc_buildFeature(uint16 enableMask, uint16 disableMask, uint8 bitfieldOffset)
{
    uint8  i;
    uint32 reg  = 0;
    uint32 mask = enableMask | (disableMask << 16);

    for (i = 0; i < IFXGTM_ATOM_NUM_AGC_CHANNELS; i++)
    {
        /* Bitfield length is 2 bits */
        uint8 shift = (i * 2) + bitfieldOffset;

        if (mask & 0x1)
        {
            reg |= IfxGtm_FeatureControl_enable << shift;
        }

        if (mask & 0x10000)
        {
            reg |= IfxGtm_FeatureControl_disable << shift;
        }

        mask = mask >> 1;
    }

    return reg;
}


uint32 IfxGtm_Atom_Agc_buildFeatureForChannel(IfxGtm_Atom_Ch channel, boolean enabled, uint8 bitfieldOffset)
{
    uint32 reg = 0;

    /* Bitfield length is 2 bits */
    uint8  shift = (((uint8)channel % 8) * 2) + bitfieldOffset;

    if (enabled == 1)
    {
        reg = IfxGtm_FeatureControl_enable << shift;
    }
    else
    {
        reg = IfxGtm_FeatureControl_disable << shift;
    }

    return reg;
}


void IfxGtm_Atom_Agc_enableChannel(Ifx_GTM_ATOM_AGC *agc, IfxGtm_Atom_Ch channel, boolean enabled, boolean immediate)
{
    uint32 value;

    value = IfxGtm_Atom_Agc_buildFeatureForChannel(channel, enabled, IFX_GTM_ATOM_AGC_ENDIS_CTRL_ENDIS_CTRL0_OFF);

    if (immediate)
    {
        agc->ENDIS_CTRL.U = value;
        agc->ENDIS_STAT.U = value;
    }
    else
    {
        agc->ENDIS_CTRL.U = value;
    }
}


void IfxGtm_Atom_Agc_enableChannelOutput(Ifx_GTM_ATOM_AGC *agc, IfxGtm_Atom_Ch channel, boolean enabled, boolean immediate)
{
    uint32 value;

    value = IfxGtm_Atom_Agc_buildFeatureForChannel(channel, enabled, IFX_GTM_ATOM_AGC_OUTEN_CTRL_OUTEN_CTRL0_OFF);

    if (immediate)
    {
        agc->OUTEN_CTRL.U = value;
        agc->OUTEN_STAT.U = value;
    }
    else
    {
        agc->OUTEN_CTRL.U = value;
    }
}


void IfxGtm_Atom_Agc_enableChannelUpdate(Ifx_GTM_ATOM_AGC *agc, IfxGtm_Atom_Ch channel, boolean enabled)
{
    agc->GLB_CTRL.U = IfxGtm_Atom_Agc_buildFeatureForChannel(channel, enabled, IFX_GTM_ATOM_AGC_GLB_CTRL_UPEN_CTRL0_OFF);
}


void IfxGtm_Atom_Agc_enableChannels(Ifx_GTM_ATOM_AGC *agc, uint16 enableMask, uint16 disableMask, boolean immediate)
{
    uint32 value;

    /* FIXME: Alann... is it possible to optimize, not always re-calculating the value using buildFeature function ? */

    value = IfxGtm_Atom_Agc_buildFeature(enableMask, disableMask, IFX_GTM_ATOM_AGC_ENDIS_CTRL_ENDIS_CTRL0_OFF);

    if (immediate)
    {
        agc->ENDIS_CTRL.U = value;
        agc->ENDIS_STAT.U = value;
    }
    else
    {
        agc->ENDIS_CTRL.U = value;
    }
}


void IfxGtm_Atom_Agc_enableChannelsOutput(Ifx_GTM_ATOM_AGC *agc, uint16 enableMask, uint16 disableMask, boolean immediate)
{
    uint32 value;

    value = IfxGtm_Atom_Agc_buildFeature(enableMask, disableMask, IFX_GTM_ATOM_AGC_OUTEN_CTRL_OUTEN_CTRL0_OFF);

    if (immediate)
    {
        agc->OUTEN_CTRL.U = value;
        agc->OUTEN_STAT.U = value;
    }
    else
    {
        agc->OUTEN_CTRL.U = value;
    }
}


void IfxGtm_Atom_Agc_enableChannelsTrigger(Ifx_GTM_ATOM_AGC *agc, uint16 enableMask, uint16 disableMask)
{
    agc->INT_TRIG.U = IfxGtm_Atom_Agc_buildFeature(enableMask, disableMask, IFX_GTM_ATOM_AGC_INT_TRIG_INT_TRIG0_OFF);
}


void IfxGtm_Atom_Agc_enableChannelsUpdate(Ifx_GTM_ATOM_AGC *agc, uint16 enableMask, uint16 disableMask)
{
    agc->GLB_CTRL.U = IfxGtm_Atom_Agc_buildFeature(enableMask, disableMask, IFX_GTM_ATOM_AGC_GLB_CTRL_UPEN_CTRL0_OFF);
}


void IfxGtm_Atom_Agc_enableTimeTrigger(Ifx_GTM_ATOM_AGC *agc, boolean enabled)
{
    agc->ACT_TB.B.TB_TRIG = enabled ? 1 : 0;
}


void IfxGtm_Atom_Agc_resetChannels(Ifx_GTM_ATOM_AGC *agc, uint32 resetMask)
{
    uint8  i;
    uint32 reg = 0;

    for (i = 0; i < IFXGTM_ATOM_NUM_AGC_CHANNELS; i++)
    {
        if (resetMask & 0x1)
        {
            reg |= 1 << i;
        }

        resetMask = resetMask >> 1;
    }

    agc->GLB_CTRL.U = reg << IFX_GTM_ATOM_AGC_GLB_CTRL_RST_CH0_OFF;
}


void IfxGtm_Atom_Agc_setChannelForceUpdate(Ifx_GTM_ATOM_AGC *agc, IfxGtm_Atom_Ch channel, boolean enabled, boolean resetEnabled)
{
    uint32 regEnable, regReset;

    regEnable        = IfxGtm_Atom_Agc_buildFeatureForChannel(channel, enabled, IFX_GTM_ATOM_AGC_FUPD_CTRL_FUPD_CTRL0_OFF);
    regReset         = IfxGtm_Atom_Agc_buildFeatureForChannel(channel, resetEnabled, IFX_GTM_ATOM_AGC_FUPD_CTRL_RSTCN0_CH0_OFF);

    agc->FUPD_CTRL.U = regEnable | (regReset << 16);
}


void IfxGtm_Atom_Agc_setChannelsForceUpdate(Ifx_GTM_ATOM_AGC *agc, uint16 enableMask, uint16 disableMask, uint16 resetEnableMask, uint16 resetDisableMask)
{
    uint32 regEnable, regReset;

    regEnable        = IfxGtm_Atom_Agc_buildFeature(enableMask, disableMask, IFX_GTM_ATOM_AGC_FUPD_CTRL_FUPD_CTRL0_OFF);
    regReset         = IfxGtm_Atom_Agc_buildFeature(resetEnableMask, resetDisableMask, IFX_GTM_ATOM_AGC_FUPD_CTRL_RSTCN0_CH0_OFF);
    agc->FUPD_CTRL.U = regEnable | regReset;
}


void IfxGtm_Atom_Agc_setTimeTrigger(Ifx_GTM_ATOM_AGC *agc, IfxGtm_Tbu_Ts base, uint32 value)
{
    Ifx_GTM_ATOM_AGC_ACT_TB act_tb;

    act_tb.U         = agc->ACT_TB.U;
    act_tb.B.TBU_SEL = base;
    act_tb.B.ACT_TB  = value;
    agc->ACT_TB.U    = act_tb.U;
}


void IfxGtm_Atom_Agc_trigger(Ifx_GTM_ATOM_AGC *agc)
{
    agc->GLB_CTRL.U = 1 << IFX_GTM_ATOM_AGC_GLB_CTRL_HOST_TRIG_OFF;
}


void IfxGtm_Atom_Ch_clearOneNotification(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->IRQ_NOTIFY.B.CCU1TC = 1;
}


void IfxGtm_Atom_Ch_clearZeroNotification(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->IRQ_NOTIFY.B.CCU0TC = 1;
}


void IfxGtm_Atom_Ch_configurePwmMode(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, IfxGtm_Cmu_Clk clock, Ifx_ActiveState activeState, IfxGtm_Atom_Ch_ResetEvent resetEvent, IfxGtm_Atom_Ch_OutputTrigger trigger)
{
    Ifx_GTM_ATOM_CH     *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);
    Ifx_GTM_ATOM_CH_CTRL ctrl;

    ctrl.U          = 0;
    ctrl.B.MODE     = IfxGtm_Atom_Mode_outputPwm;

    ctrl.B.CLK_SRC  = clock;

    ctrl.B.RST_CCU0 = resetEvent;
    ctrl.B.SL       = (activeState == Ifx_ActiveState_high ? 1 : 0);
    ctrl.B.TRIGOUT  = trigger;

    atomCh->CTRL.U  = ctrl.U;
}


float32 IfxGtm_Atom_Ch_getClockFrequency(Ifx_GTM *gtm, Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    IfxGtm_Cmu_Clk clock;

    clock = IfxGtm_Atom_Ch_getClockSource(atom, channel);

    return IfxGtm_Cmu_getClkFrequency(gtm, clock, TRUE);
}


IfxGtm_Cmu_Clk IfxGtm_Atom_Ch_getClockSource(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    IfxGtm_Cmu_Clk   clock;
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);
    clock = atomCh->CTRL.B.CLK_SRC;

    return clock;
}


uint32 IfxGtm_Atom_Ch_getCompareOne(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    return atomCh->CM1.U;
}


volatile uint32 *IfxGtm_Atom_Ch_getCompareOnePointer(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    return (volatile uint32 *)&atomCh->CM1;
}


uint32 IfxGtm_Atom_Ch_getCompareZero(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    return atomCh->CM0.U;
}


volatile uint32 *IfxGtm_Atom_Ch_getCompareZeroPointer(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    return (volatile uint32 *)&atomCh->CM0;
}


boolean IfxGtm_Atom_Ch_getOutputLevel(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    boolean          result;
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    result = atomCh->STAT.B.OL == 1;

    return result;
}


volatile Ifx_SRC_SRCR *IfxGtm_Atom_Ch_getSrcPointer(Ifx_GTM *gtm, IfxGtm_Atom atom, IfxGtm_Atom_Ch channel)
{
    return &MODULE_SRC.GTM.GTM[0].ATOM[atom][channel / 2];
}


volatile uint32 *IfxGtm_Atom_Ch_getTimerPointer(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    return (volatile uint32 *)((uint32)&(atom->CH0.CN0.U) + channel * (offsetof(Ifx_GTM_ATOM, CH1) - offsetof(Ifx_GTM_ATOM, CH0)));
}


boolean IfxGtm_Atom_Ch_isOneNotification(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    boolean          result;
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);
    result = atomCh->IRQ_NOTIFY.B.CCU1TC != 0;
    return result;
}


boolean IfxGtm_Atom_Ch_isZeroNotification(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    boolean          result;
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);
    result = atomCh->IRQ_NOTIFY.B.CCU0TC != 0;
    return result;
}


void IfxGtm_Atom_Ch_raiseInterruptOne(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->IRQ_FORCINT.B.TRG_CCU1TC = 1;
}


void IfxGtm_Atom_Ch_raiseInterruptZero(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->IRQ_FORCINT.B.TRG_CCU0TC = 1;
}


void IfxGtm_Atom_Ch_setClockSource(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, IfxGtm_Cmu_Clk clock)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->CTRL.B.CLK_SRC = clock;
}


void IfxGtm_Atom_Ch_setCompare(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, uint32 compareZero, uint32 compareOne)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->CM0.U = compareZero; // TK: replaced .B access to optimize runtime
    atomCh->CM1.U = compareOne;
}


void IfxGtm_Atom_Ch_setCompareOne(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, uint32 compareOne)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->CM1.U = compareOne; // TK: replaced .B access to optimize runtime
}


void IfxGtm_Atom_Ch_setCompareOneShadow(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, uint32 shadowOne)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->SR1.U = shadowOne; // TK: replaced .B access to optimize runtime
}


void IfxGtm_Atom_Ch_setCompareZero(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, uint32 compareZero)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->CM0.U = compareZero; // TK: replaced .B access to optimize runtime
}


void IfxGtm_Atom_Ch_setCompareZeroShadow(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, uint32 shadowZero)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->SR0.U = shadowZero; // TK: replaced .B access to optimize runtime
}


void IfxGtm_Atom_Ch_setCounterValue(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, uint32 value)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->CN0.U = value; // TK: replaced .B access to optimize runtime
}


void IfxGtm_Atom_Ch_setMode(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, IfxGtm_Atom_Mode mode)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->CTRL.B.MODE = mode;
}


void IfxGtm_Atom_Ch_setNotification(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, IfxGtm_IrqMode mode, boolean interruptOnCompareZero, boolean interruptOnCompareOne)
{
    Ifx_GTM_ATOM_CH       *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    Ifx_GTM_ATOM_CH_IRQ_EN en;
    en.U = atomCh->IRQ_EN.U;

    /* Disable all interrupts of the interrupt set to change mode */
    atomCh->IRQ_EN.U            = IFX_ZEROS;
    atomCh->IRQ_MODE.B.IRQ_MODE = mode;
    atomCh->IRQ_EN.U            = en.U; /* Set the values back */

    en.B.CCU0TC_IRQ_EN          = interruptOnCompareZero ? 1 : 0;
    en.B.CCU1TC_IRQ_EN          = interruptOnCompareOne ? 1 : 0;
    atomCh->IRQ_EN.U            = en.U;
}


void IfxGtm_Atom_Ch_setOneShotMode(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, boolean enabled)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->CTRL.B.OSM = enabled ? 1 : 0;
}


void IfxGtm_Atom_Ch_setResetSource(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, IfxGtm_Atom_Ch_ResetEvent event)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->CTRL.B.RST_CCU0 = event;
}


void IfxGtm_Atom_Ch_setSignalLevel(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, Ifx_ActiveState activeState)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->CTRL.B.SL = activeState == Ifx_ActiveState_high ? 1 : 0;
}


void IfxGtm_Atom_Ch_setTriggerOutput(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, IfxGtm_Atom_Ch_OutputTrigger trigger)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->CTRL.B.TRIGOUT = trigger;
}


void IfxGtm_Atom_Ch_setAruInput(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, boolean enabled)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->CTRL.B.ARU_EN = enabled;
}


uint32 IfxGtm_Atom_Ch_getCounterValue(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    return atomCh->CN0.U;
}


void IfxGtm_Atom_Ch_setSomcControl(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, IfxGtm_Atom_SomcControl control)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->SOMC.B.ACB42 = control;
}


void IfxGtm_Atom_Ch_setSomcSignalLevelControl(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, IfxGtm_Atom_SomcSignalLevelControl ctrl)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);

    atomCh->SOMC.B.ACB10 = ctrl;
}


void IfxGtm_Atom_Ch_setAruReadAddress0(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, uint32 address)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);
    atomCh->RDADDR.B.RDADDR0 = address;
}


void IfxGtm_Atom_Ch_setAruReadAddress1(Ifx_GTM_ATOM *atom, IfxGtm_Atom_Ch channel, uint32 address)
{
    Ifx_GTM_ATOM_CH *atomCh = IfxGtm_Atom_Ch_getChannelPointer(atom, channel);
    atomCh->RDADDR.B.RDADDR1 = address;
}

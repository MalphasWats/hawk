/**
 * \file
 *
 * \brief Instance description for TC1
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef _SAMD10_TC1_INSTANCE_
#define _SAMD10_TC1_INSTANCE_

/* ========== Register definition for TC1 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_TC1_CTRLA              (0x42001800U) /**< \brief (TC1) Control A */
#define REG_TC1_READREQ            (0x42001802U) /**< \brief (TC1) Read Request */
#define REG_TC1_CTRLBCLR           (0x42001804U) /**< \brief (TC1) Control B Clear */
#define REG_TC1_CTRLBSET           (0x42001805U) /**< \brief (TC1) Control B Set */
#define REG_TC1_CTRLC              (0x42001806U) /**< \brief (TC1) Control C */
#define REG_TC1_DBGCTRL            (0x42001808U) /**< \brief (TC1) Debug Control */
#define REG_TC1_EVCTRL             (0x4200180AU) /**< \brief (TC1) Event Control */
#define REG_TC1_INTENCLR           (0x4200180CU) /**< \brief (TC1) Interrupt Enable Clear */
#define REG_TC1_INTENSET           (0x4200180DU) /**< \brief (TC1) Interrupt Enable Set */
#define REG_TC1_INTFLAG            (0x4200180EU) /**< \brief (TC1) Interrupt Flag Status and Clear */
#define REG_TC1_STATUS             (0x4200180FU) /**< \brief (TC1) Status */
#define REG_TC1_COUNT16_COUNT      (0x42001810U) /**< \brief (TC1) COUNT16 Counter Value */
#define REG_TC1_COUNT16_CC0        (0x42001818U) /**< \brief (TC1) COUNT16 Compare/Capture 0 */
#define REG_TC1_COUNT16_CC1        (0x4200181AU) /**< \brief (TC1) COUNT16 Compare/Capture 1 */
#define REG_TC1_COUNT32_COUNT      (0x42001810U) /**< \brief (TC1) COUNT32 Counter Value */
#define REG_TC1_COUNT32_CC0        (0x42001818U) /**< \brief (TC1) COUNT32 Compare/Capture 0 */
#define REG_TC1_COUNT32_CC1        (0x4200181CU) /**< \brief (TC1) COUNT32 Compare/Capture 1 */
#define REG_TC1_COUNT8_COUNT       (0x42001810U) /**< \brief (TC1) COUNT8 Counter Value */
#define REG_TC1_COUNT8_PER         (0x42001814U) /**< \brief (TC1) COUNT8 Period Value */
#define REG_TC1_COUNT8_CC0         (0x42001818U) /**< \brief (TC1) COUNT8 Compare/Capture 0 */
#define REG_TC1_COUNT8_CC1         (0x42001819U) /**< \brief (TC1) COUNT8 Compare/Capture 1 */
#else
#define REG_TC1_CTRLA              (*(RwReg16*)0x42001800U) /**< \brief (TC1) Control A */
#define REG_TC1_READREQ            (*(RwReg16*)0x42001802U) /**< \brief (TC1) Read Request */
#define REG_TC1_CTRLBCLR           (*(RwReg8 *)0x42001804U) /**< \brief (TC1) Control B Clear */
#define REG_TC1_CTRLBSET           (*(RwReg8 *)0x42001805U) /**< \brief (TC1) Control B Set */
#define REG_TC1_CTRLC              (*(RwReg8 *)0x42001806U) /**< \brief (TC1) Control C */
#define REG_TC1_DBGCTRL            (*(RwReg8 *)0x42001808U) /**< \brief (TC1) Debug Control */
#define REG_TC1_EVCTRL             (*(RwReg16*)0x4200180AU) /**< \brief (TC1) Event Control */
#define REG_TC1_INTENCLR           (*(RwReg8 *)0x4200180CU) /**< \brief (TC1) Interrupt Enable Clear */
#define REG_TC1_INTENSET           (*(RwReg8 *)0x4200180DU) /**< \brief (TC1) Interrupt Enable Set */
#define REG_TC1_INTFLAG            (*(RwReg8 *)0x4200180EU) /**< \brief (TC1) Interrupt Flag Status and Clear */
#define REG_TC1_STATUS             (*(RoReg8 *)0x4200180FU) /**< \brief (TC1) Status */
#define REG_TC1_COUNT16_COUNT      (*(RwReg16*)0x42001810U) /**< \brief (TC1) COUNT16 Counter Value */
#define REG_TC1_COUNT16_CC0        (*(RwReg16*)0x42001818U) /**< \brief (TC1) COUNT16 Compare/Capture 0 */
#define REG_TC1_COUNT16_CC1        (*(RwReg16*)0x4200181AU) /**< \brief (TC1) COUNT16 Compare/Capture 1 */
#define REG_TC1_COUNT32_COUNT      (*(RwReg  *)0x42001810U) /**< \brief (TC1) COUNT32 Counter Value */
#define REG_TC1_COUNT32_CC0        (*(RwReg  *)0x42001818U) /**< \brief (TC1) COUNT32 Compare/Capture 0 */
#define REG_TC1_COUNT32_CC1        (*(RwReg  *)0x4200181CU) /**< \brief (TC1) COUNT32 Compare/Capture 1 */
#define REG_TC1_COUNT8_COUNT       (*(RwReg8 *)0x42001810U) /**< \brief (TC1) COUNT8 Counter Value */
#define REG_TC1_COUNT8_PER         (*(RwReg8 *)0x42001814U) /**< \brief (TC1) COUNT8 Period Value */
#define REG_TC1_COUNT8_CC0         (*(RwReg8 *)0x42001818U) /**< \brief (TC1) COUNT8 Compare/Capture 0 */
#define REG_TC1_COUNT8_CC1         (*(RwReg8 *)0x42001819U) /**< \brief (TC1) COUNT8 Compare/Capture 1 */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for TC1 peripheral ========== */
#define TC1_CC8_NUM                 2        // Number of 8-bit Counters
#define TC1_CC16_NUM                2        // Number of 16-bit Counters
#define TC1_CC32_NUM                2        // Number of 32-bit Counters
#define TC1_DITHERING_EXT           0        // Dithering feature implemented
#define TC1_DMAC_ID_MC_0            13
#define TC1_DMAC_ID_MC_1            14
#define TC1_DMAC_ID_MC_LSB          13
#define TC1_DMAC_ID_MC_MSB          14
#define TC1_DMAC_ID_MC_SIZE         2
#define TC1_DMAC_ID_OVF             12       // Indexes of DMA Overflow trigger
#define TC1_GCLK_ID                 18       // Index of Generic Clock
#define TC1_MASTER                  1       
#define TC1_OW_NUM                  2        // Number of Output Waveforms
#define TC1_PERIOD_EXT              0        // Period feature implemented
#define TC1_SHADOW_EXT              0        // Shadow feature implemented

#endif /* _SAMD10_TC1_INSTANCE_ */

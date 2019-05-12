/**
 * \file
 *
 * \brief Instance description for TCC0
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

#ifndef _SAMD10_TCC0_INSTANCE_
#define _SAMD10_TCC0_INSTANCE_

/* ========== Register definition for TCC0 peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_TCC0_CTRLA             (0x42001400U) /**< \brief (TCC0) Control A */
#define REG_TCC0_CTRLBCLR          (0x42001404U) /**< \brief (TCC0) Control B Clear */
#define REG_TCC0_CTRLBSET          (0x42001405U) /**< \brief (TCC0) Control B Set */
#define REG_TCC0_SYNCBUSY          (0x42001408U) /**< \brief (TCC0) Synchronization Busy */
#define REG_TCC0_FCTRLA            (0x4200140CU) /**< \brief (TCC0) Recoverable Fault A Configuration */
#define REG_TCC0_FCTRLB            (0x42001410U) /**< \brief (TCC0) Recoverable Fault B Configuration */
#define REG_TCC0_WEXCTRL           (0x42001414U) /**< \brief (TCC0) Waveform Extension Configuration */
#define REG_TCC0_DRVCTRL           (0x42001418U) /**< \brief (TCC0) Driver Control */
#define REG_TCC0_DBGCTRL           (0x4200141EU) /**< \brief (TCC0) Debug Control */
#define REG_TCC0_EVCTRL            (0x42001420U) /**< \brief (TCC0) Event Control */
#define REG_TCC0_INTENCLR          (0x42001424U) /**< \brief (TCC0) Interrupt Enable Clear */
#define REG_TCC0_INTENSET          (0x42001428U) /**< \brief (TCC0) Interrupt Enable Set */
#define REG_TCC0_INTFLAG           (0x4200142CU) /**< \brief (TCC0) Interrupt Flag Status and Clear */
#define REG_TCC0_STATUS            (0x42001430U) /**< \brief (TCC0) Status */
#define REG_TCC0_COUNT             (0x42001434U) /**< \brief (TCC0) Count */
#define REG_TCC0_PATT              (0x42001438U) /**< \brief (TCC0) Pattern */
#define REG_TCC0_WAVE              (0x4200143CU) /**< \brief (TCC0) Waveform Control */
#define REG_TCC0_PER               (0x42001440U) /**< \brief (TCC0) Period */
#define REG_TCC0_CC0               (0x42001444U) /**< \brief (TCC0) Compare and Capture 0 */
#define REG_TCC0_CC1               (0x42001448U) /**< \brief (TCC0) Compare and Capture 1 */
#define REG_TCC0_CC2               (0x4200144CU) /**< \brief (TCC0) Compare and Capture 2 */
#define REG_TCC0_CC3               (0x42001450U) /**< \brief (TCC0) Compare and Capture 3 */
#define REG_TCC0_PATTB             (0x42001464U) /**< \brief (TCC0) Pattern Buffer */
#define REG_TCC0_WAVEB             (0x42001468U) /**< \brief (TCC0) Waveform Control Buffer */
#define REG_TCC0_PERB              (0x4200146CU) /**< \brief (TCC0) Period Buffer */
#define REG_TCC0_CCB0              (0x42001470U) /**< \brief (TCC0) Compare and Capture Buffer 0 */
#define REG_TCC0_CCB1              (0x42001474U) /**< \brief (TCC0) Compare and Capture Buffer 1 */
#define REG_TCC0_CCB2              (0x42001478U) /**< \brief (TCC0) Compare and Capture Buffer 2 */
#define REG_TCC0_CCB3              (0x4200147CU) /**< \brief (TCC0) Compare and Capture Buffer 3 */
#else
#define REG_TCC0_CTRLA             (*(RwReg  *)0x42001400U) /**< \brief (TCC0) Control A */
#define REG_TCC0_CTRLBCLR          (*(RwReg8 *)0x42001404U) /**< \brief (TCC0) Control B Clear */
#define REG_TCC0_CTRLBSET          (*(RwReg8 *)0x42001405U) /**< \brief (TCC0) Control B Set */
#define REG_TCC0_SYNCBUSY          (*(RoReg  *)0x42001408U) /**< \brief (TCC0) Synchronization Busy */
#define REG_TCC0_FCTRLA            (*(RwReg  *)0x4200140CU) /**< \brief (TCC0) Recoverable Fault A Configuration */
#define REG_TCC0_FCTRLB            (*(RwReg  *)0x42001410U) /**< \brief (TCC0) Recoverable Fault B Configuration */
#define REG_TCC0_WEXCTRL           (*(RwReg  *)0x42001414U) /**< \brief (TCC0) Waveform Extension Configuration */
#define REG_TCC0_DRVCTRL           (*(RwReg  *)0x42001418U) /**< \brief (TCC0) Driver Control */
#define REG_TCC0_DBGCTRL           (*(RwReg8 *)0x4200141EU) /**< \brief (TCC0) Debug Control */
#define REG_TCC0_EVCTRL            (*(RwReg  *)0x42001420U) /**< \brief (TCC0) Event Control */
#define REG_TCC0_INTENCLR          (*(RwReg  *)0x42001424U) /**< \brief (TCC0) Interrupt Enable Clear */
#define REG_TCC0_INTENSET          (*(RwReg  *)0x42001428U) /**< \brief (TCC0) Interrupt Enable Set */
#define REG_TCC0_INTFLAG           (*(RwReg  *)0x4200142CU) /**< \brief (TCC0) Interrupt Flag Status and Clear */
#define REG_TCC0_STATUS            (*(RwReg  *)0x42001430U) /**< \brief (TCC0) Status */
#define REG_TCC0_COUNT             (*(RwReg  *)0x42001434U) /**< \brief (TCC0) Count */
#define REG_TCC0_PATT              (*(RwReg16*)0x42001438U) /**< \brief (TCC0) Pattern */
#define REG_TCC0_WAVE              (*(RwReg  *)0x4200143CU) /**< \brief (TCC0) Waveform Control */
#define REG_TCC0_PER               (*(RwReg  *)0x42001440U) /**< \brief (TCC0) Period */
#define REG_TCC0_CC0               (*(RwReg  *)0x42001444U) /**< \brief (TCC0) Compare and Capture 0 */
#define REG_TCC0_CC1               (*(RwReg  *)0x42001448U) /**< \brief (TCC0) Compare and Capture 1 */
#define REG_TCC0_CC2               (*(RwReg  *)0x4200144CU) /**< \brief (TCC0) Compare and Capture 2 */
#define REG_TCC0_CC3               (*(RwReg  *)0x42001450U) /**< \brief (TCC0) Compare and Capture 3 */
#define REG_TCC0_PATTB             (*(RwReg16*)0x42001464U) /**< \brief (TCC0) Pattern Buffer */
#define REG_TCC0_WAVEB             (*(RwReg  *)0x42001468U) /**< \brief (TCC0) Waveform Control Buffer */
#define REG_TCC0_PERB              (*(RwReg  *)0x4200146CU) /**< \brief (TCC0) Period Buffer */
#define REG_TCC0_CCB0              (*(RwReg  *)0x42001470U) /**< \brief (TCC0) Compare and Capture Buffer 0 */
#define REG_TCC0_CCB1              (*(RwReg  *)0x42001474U) /**< \brief (TCC0) Compare and Capture Buffer 1 */
#define REG_TCC0_CCB2              (*(RwReg  *)0x42001478U) /**< \brief (TCC0) Compare and Capture Buffer 2 */
#define REG_TCC0_CCB3              (*(RwReg  *)0x4200147CU) /**< \brief (TCC0) Compare and Capture Buffer 3 */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for TCC0 peripheral ========== */
#define TCC0_CC_NUM                 4        // Number of Compare/Capture units
#define TCC0_DITHERING              1        // Dithering feature implemented
#define TCC0_DMAC_ID_MC_0           8
#define TCC0_DMAC_ID_MC_1           9
#define TCC0_DMAC_ID_MC_2           10
#define TCC0_DMAC_ID_MC_3           11
#define TCC0_DMAC_ID_MC_LSB         8
#define TCC0_DMAC_ID_MC_MSB         11
#define TCC0_DMAC_ID_MC_SIZE        4
#define TCC0_DMAC_ID_OVF            7        // DMA overflow/underflow/retrigger trigger
#define TCC0_DTI                    1        // Dead-Time-Insertion feature implemented
#define TCC0_EXT                    31       // (@_DITHERING*16+@_PG*8+@_SWAP*4+@_DTI*2+@_OTMX*1)
#define TCC0_GCLK_ID                17       // Index of Generic Clock
#define TCC0_MASTER                 0       
#define TCC0_OTMX                   1        // Output Matrix feature implemented
#define TCC0_OW_NUM                 8        // Number of Output Waveforms
#define TCC0_PG                     1        // Pattern Generation feature implemented
#define TCC0_SIZE                   24      
#define TCC0_SWAP                   1        // DTI outputs swap feature implemented

#endif /* _SAMD10_TCC0_INSTANCE_ */

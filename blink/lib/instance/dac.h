/**
 * \file
 *
 * \brief Instance description for DAC
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

#ifndef _SAMD10_DAC_INSTANCE_
#define _SAMD10_DAC_INSTANCE_

/* ========== Register definition for DAC peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_DAC_CTRLA              (0x42002800U) /**< \brief (DAC) Control A */
#define REG_DAC_CTRLB              (0x42002801U) /**< \brief (DAC) Control B */
#define REG_DAC_EVCTRL             (0x42002802U) /**< \brief (DAC) Event Control */
#define REG_DAC_INTENCLR           (0x42002804U) /**< \brief (DAC) Interrupt Enable Clear */
#define REG_DAC_INTENSET           (0x42002805U) /**< \brief (DAC) Interrupt Enable Set */
#define REG_DAC_INTFLAG            (0x42002806U) /**< \brief (DAC) Interrupt Flag Status and Clear */
#define REG_DAC_STATUS             (0x42002807U) /**< \brief (DAC) Status */
#define REG_DAC_DATA               (0x42002808U) /**< \brief (DAC) Data */
#define REG_DAC_DATABUF            (0x4200280CU) /**< \brief (DAC) Data Buffer */
#else
#define REG_DAC_CTRLA              (*(RwReg8 *)0x42002800U) /**< \brief (DAC) Control A */
#define REG_DAC_CTRLB              (*(RwReg8 *)0x42002801U) /**< \brief (DAC) Control B */
#define REG_DAC_EVCTRL             (*(RwReg8 *)0x42002802U) /**< \brief (DAC) Event Control */
#define REG_DAC_INTENCLR           (*(RwReg8 *)0x42002804U) /**< \brief (DAC) Interrupt Enable Clear */
#define REG_DAC_INTENSET           (*(RwReg8 *)0x42002805U) /**< \brief (DAC) Interrupt Enable Set */
#define REG_DAC_INTFLAG            (*(RwReg8 *)0x42002806U) /**< \brief (DAC) Interrupt Flag Status and Clear */
#define REG_DAC_STATUS             (*(RoReg8 *)0x42002807U) /**< \brief (DAC) Status */
#define REG_DAC_DATA               (*(RwReg16*)0x42002808U) /**< \brief (DAC) Data */
#define REG_DAC_DATABUF            (*(RwReg16*)0x4200280CU) /**< \brief (DAC) Data Buffer */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for DAC peripheral ========== */
#define DAC_DMAC_ID_EMPTY           19       // Index of DMAC EMPTY trigger
#define DAC_GCLK_ID                 22       // Index of Generic Clock

#endif /* _SAMD10_DAC_INSTANCE_ */

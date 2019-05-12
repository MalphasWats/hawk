/**
 * \file
 *
 * \brief Instance description for EIC
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

#ifndef _SAMD10_EIC_INSTANCE_
#define _SAMD10_EIC_INSTANCE_

/* ========== Register definition for EIC peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_EIC_CTRL               (0x40001800U) /**< \brief (EIC) Control */
#define REG_EIC_STATUS             (0x40001801U) /**< \brief (EIC) Status */
#define REG_EIC_NMICTRL            (0x40001802U) /**< \brief (EIC) Non-Maskable Interrupt Control */
#define REG_EIC_NMIFLAG            (0x40001803U) /**< \brief (EIC) Non-Maskable Interrupt Flag Status and Clear */
#define REG_EIC_EVCTRL             (0x40001804U) /**< \brief (EIC) Event Control */
#define REG_EIC_INTENCLR           (0x40001808U) /**< \brief (EIC) Interrupt Enable Clear */
#define REG_EIC_INTENSET           (0x4000180CU) /**< \brief (EIC) Interrupt Enable Set */
#define REG_EIC_INTFLAG            (0x40001810U) /**< \brief (EIC) Interrupt Flag Status and Clear */
#define REG_EIC_WAKEUP             (0x40001814U) /**< \brief (EIC) Wake-Up Enable */
#define REG_EIC_CONFIG0            (0x40001818U) /**< \brief (EIC) Configuration 0 */
#else
#define REG_EIC_CTRL               (*(RwReg8 *)0x40001800U) /**< \brief (EIC) Control */
#define REG_EIC_STATUS             (*(RoReg8 *)0x40001801U) /**< \brief (EIC) Status */
#define REG_EIC_NMICTRL            (*(RwReg8 *)0x40001802U) /**< \brief (EIC) Non-Maskable Interrupt Control */
#define REG_EIC_NMIFLAG            (*(RwReg8 *)0x40001803U) /**< \brief (EIC) Non-Maskable Interrupt Flag Status and Clear */
#define REG_EIC_EVCTRL             (*(RwReg  *)0x40001804U) /**< \brief (EIC) Event Control */
#define REG_EIC_INTENCLR           (*(RwReg  *)0x40001808U) /**< \brief (EIC) Interrupt Enable Clear */
#define REG_EIC_INTENSET           (*(RwReg  *)0x4000180CU) /**< \brief (EIC) Interrupt Enable Set */
#define REG_EIC_INTFLAG            (*(RwReg  *)0x40001810U) /**< \brief (EIC) Interrupt Flag Status and Clear */
#define REG_EIC_WAKEUP             (*(RwReg  *)0x40001814U) /**< \brief (EIC) Wake-Up Enable */
#define REG_EIC_CONFIG0            (*(RwReg  *)0x40001818U) /**< \brief (EIC) Configuration 0 */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for EIC peripheral ========== */
#define EIC_CONFIG_NUM              1        // Number of CONFIG registers
#define EIC_EXTINT_NUM              8        // Number of External Interrupts
#define EIC_GCLK_ID                 5        // Index of Generic Clock

#endif /* _SAMD10_EIC_INSTANCE_ */

/**
 * \file
 *
 * \brief Instance description for PORT
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

#ifndef _SAMD10_PORT_INSTANCE_
#define _SAMD10_PORT_INSTANCE_

/* ========== Register definition for PORT peripheral ========== */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define REG_PORT_DIR0              (0x41004400U) /**< \brief (PORT) Data Direction 0 */
#define REG_PORT_DIRCLR0           (0x41004404U) /**< \brief (PORT) Data Direction Clear 0 */
#define REG_PORT_DIRSET0           (0x41004408U) /**< \brief (PORT) Data Direction Set 0 */
#define REG_PORT_DIRTGL0           (0x4100440CU) /**< \brief (PORT) Data Direction Toggle 0 */
#define REG_PORT_OUT0              (0x41004410U) /**< \brief (PORT) Data Output Value 0 */
#define REG_PORT_OUTCLR0           (0x41004414U) /**< \brief (PORT) Data Output Value Clear 0 */
#define REG_PORT_OUTSET0           (0x41004418U) /**< \brief (PORT) Data Output Value Set 0 */
#define REG_PORT_OUTTGL0           (0x4100441CU) /**< \brief (PORT) Data Output Value Toggle 0 */
#define REG_PORT_IN0               (0x41004420U) /**< \brief (PORT) Data Input Value 0 */
#define REG_PORT_CTRL0             (0x41004424U) /**< \brief (PORT) Control 0 */
#define REG_PORT_WRCONFIG0         (0x41004428U) /**< \brief (PORT) Write Configuration 0 */
#define REG_PORT_PMUX0             (0x41004430U) /**< \brief (PORT) Peripheral Multiplexing 0 */
#define REG_PORT_PINCFG0           (0x41004440U) /**< \brief (PORT) Pin Configuration 0 */
#else
#define REG_PORT_DIR0              (*(RwReg  *)0x41004400U) /**< \brief (PORT) Data Direction 0 */
#define REG_PORT_DIRCLR0           (*(RwReg  *)0x41004404U) /**< \brief (PORT) Data Direction Clear 0 */
#define REG_PORT_DIRSET0           (*(RwReg  *)0x41004408U) /**< \brief (PORT) Data Direction Set 0 */
#define REG_PORT_DIRTGL0           (*(RwReg  *)0x4100440CU) /**< \brief (PORT) Data Direction Toggle 0 */
#define REG_PORT_OUT0              (*(RwReg  *)0x41004410U) /**< \brief (PORT) Data Output Value 0 */
#define REG_PORT_OUTCLR0           (*(RwReg  *)0x41004414U) /**< \brief (PORT) Data Output Value Clear 0 */
#define REG_PORT_OUTSET0           (*(RwReg  *)0x41004418U) /**< \brief (PORT) Data Output Value Set 0 */
#define REG_PORT_OUTTGL0           (*(RwReg  *)0x4100441CU) /**< \brief (PORT) Data Output Value Toggle 0 */
#define REG_PORT_IN0               (*(RoReg  *)0x41004420U) /**< \brief (PORT) Data Input Value 0 */
#define REG_PORT_CTRL0             (*(RwReg  *)0x41004424U) /**< \brief (PORT) Control 0 */
#define REG_PORT_WRCONFIG0         (*(WoReg  *)0x41004428U) /**< \brief (PORT) Write Configuration 0 */
#define REG_PORT_PMUX0             (*(RwReg  *)0x41004430U) /**< \brief (PORT) Peripheral Multiplexing 0 */
#define REG_PORT_PINCFG0           (*(RwReg  *)0x41004440U) /**< \brief (PORT) Pin Configuration 0 */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ========== Instance parameters for PORT peripheral ========== */
#define PORT_BITS                   32       // Number of PORT pins
#define PORT_DIR_DEFAULT_VAL        { 0x00000000 } // Default value for DIR of all pins
#define PORT_DIR_IMPLEMENTED        { 0xDBC3CFFC } // Implementation mask for DIR of all pins
#define PORT_DRVSTR                 1        // DRVSTR supported
#define PORT_DRVSTR_DEFAULT_VAL     { 0x00000000 } // Default value for DRVSTR of all pins
#define PORT_DRVSTR_IMPLEMENTED     { 0xD8C3CFFC } // Implementation mask for DRVSTR of all pins
#define PORT_EVENT_IMPLEMENTED      { 0x00000000 }
#define PORT_GROUPS                 1        // Number of 32-bit PORT groups
#define PORT_INEN_DEFAULT_VAL       { 0x10000000 } // Default value for INEN of all pins
#define PORT_INEN_IMPLEMENTED       { 0xDBC3CFFC } // Implementation mask for INEN of all pins
#define PORT_ODRAIN                 0        // ODRAIN supported
#define PORT_ODRAIN_DEFAULT_VAL     { 0x00000000 } // Default value for ODRAIN of all pins
#define PORT_ODRAIN_IMPLEMENTED     { 0x00000000 } // Implementation mask for ODRAIN of all pins
#define PORT_OUT_DEFAULT_VAL        { 0x10000000 } // Default value for OUT of all pins
#define PORT_OUT_IMPLEMENTED        { 0xDBC3CFFC } // Implementation mask for OUT of all pins
#define PORT_PIN_IMPLEMENTED        { 0xDBC3CFFC } // Implementation mask for all PORT pins
#define PORT_PMUXBIT0_DEFAULT_VAL   { 0x00000000 } // Default value for PMUX[0] of all pins
#define PORT_PMUXBIT0_IMPLEMENTED   { 0xCBC3CFFC } // Implementation mask for PMUX[0] of all pins
#define PORT_PMUXBIT1_DEFAULT_VAL   { 0x40000000 } // Default value for PMUX[1] of all pins
#define PORT_PMUXBIT1_IMPLEMENTED   { 0xCBC3CFF0 } // Implementation mask for PMUX[1] of all pins
#define PORT_PMUXBIT2_DEFAULT_VAL   { 0x40000000 } // Default value for PMUX[2] of all pins
#define PORT_PMUXBIT2_IMPLEMENTED   { 0xCBC3CFF0 } // Implementation mask for PMUX[2] of all pins
#define PORT_PMUXBIT3_DEFAULT_VAL   { 0x00000000 } // Default value for PMUX[3] of all pins
#define PORT_PMUXBIT3_IMPLEMENTED   { 0x00000000 } // Implementation mask for PMUX[3] of all pins
#define PORT_PMUXEN_DEFAULT_VAL     { 0x643C3003 } // Default value for PMUXEN of all pins
#define PORT_PMUXEN_IMPLEMENTED     { 0xCBC3CFFC } // Implementation mask for PMUXEN of all pins
#define PORT_PULLEN_DEFAULT_VAL     { 0x10000000 } // Default value for PULLEN of all pins
#define PORT_PULLEN_IMPLEMENTED     { 0xDBC3CFFC } // Implementation mask for PULLEN of all pins
#define PORT_SLEWLIM                0        // SLEWLIM supported
#define PORT_SLEWLIM_DEFAULT_VAL    { 0x00000000 } // Default value for SLEWLIM of all pins
#define PORT_SLEWLIM_IMPLEMENTED    { 0x00000000 } // Implementation mask for SLEWLIM of all pins

#endif /* _SAMD10_PORT_INSTANCE_ */

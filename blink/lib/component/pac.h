/**
 * \file
 *
 * \brief Component description for PAC
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

#ifndef _SAMD10_PAC_COMPONENT_
#define _SAMD10_PAC_COMPONENT_

/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR PAC */
/* ========================================================================== */
/** \addtogroup SAMD10_PAC Peripheral Access Controller */
/*@{*/

#define PAC_U2211
#define REV_PAC                     0x101

/* -------- PAC_WPCLR : (PAC Offset: 0x0) (R/W 32) Write Protection Clear -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t :1;               /*!< bit:      0  Reserved                           */
    uint32_t WP:31;            /*!< bit:  1..31  Write Protection Clear             */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} PAC_WPCLR_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PAC_WPCLR_OFFSET            0x0          /**< \brief (PAC_WPCLR offset) Write Protection Clear */
#define PAC_WPCLR_RESETVALUE        0x00000000ul /**< \brief (PAC_WPCLR reset_value) Write Protection Clear */

#define PAC_WPCLR_WP_Pos            1            /**< \brief (PAC_WPCLR) Write Protection Clear */
#define PAC_WPCLR_WP_Msk            (0x7FFFFFFFul << PAC_WPCLR_WP_Pos)
#define PAC_WPCLR_WP(value)         (PAC_WPCLR_WP_Msk & ((value) << PAC_WPCLR_WP_Pos))
#define PAC_WPCLR_MASK              0xFFFFFFFEul /**< \brief (PAC_WPCLR) MASK Register */

/* -------- PAC_WPSET : (PAC Offset: 0x4) (R/W 32) Write Protection Set -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    uint32_t :1;               /*!< bit:      0  Reserved                           */
    uint32_t WP:31;            /*!< bit:  1..31  Write Protection Set               */
  } bit;                       /*!< Structure used for bit  access                  */
  uint32_t reg;                /*!< Type      used for register access              */
} PAC_WPSET_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PAC_WPSET_OFFSET            0x4          /**< \brief (PAC_WPSET offset) Write Protection Set */
#define PAC_WPSET_RESETVALUE        0x00000000ul /**< \brief (PAC_WPSET reset_value) Write Protection Set */

#define PAC_WPSET_WP_Pos            1            /**< \brief (PAC_WPSET) Write Protection Set */
#define PAC_WPSET_WP_Msk            (0x7FFFFFFFul << PAC_WPSET_WP_Pos)
#define PAC_WPSET_WP(value)         (PAC_WPSET_WP_Msk & ((value) << PAC_WPSET_WP_Pos))
#define PAC_WPSET_MASK              0xFFFFFFFEul /**< \brief (PAC_WPSET) MASK Register */

/** \brief PAC hardware registers */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct {
  __IO PAC_WPCLR_Type            WPCLR;       /**< \brief Offset: 0x0 (R/W 32) Write Protection Clear */
  __IO PAC_WPSET_Type            WPSET;       /**< \brief Offset: 0x4 (R/W 32) Write Protection Set */
} Pac;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/*@}*/

#endif /* _SAMD10_PAC_COMPONENT_ */

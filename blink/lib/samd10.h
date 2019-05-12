/**
 * \file
 *
 * \brief Top header file for SAMD10
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

#ifndef _SAMD10_
#define _SAMD10_

/**
 * \defgroup SAMD10_definitions SAMD10 Device Definitions
 * \brief SAMD10 CMSIS Definitions.
 */

#if   defined(__SAMD10C12A__) || defined(__ATSAMD10C12A__)
  #include "samd10c12a.h"
#elif defined(__SAMD10C13A__) || defined(__ATSAMD10C13A__)
  #include "samd10c13a.h"
#elif defined(__SAMD10C14A__) || defined(__ATSAMD10C14A__)
  #include "samd10c14a.h"
#elif defined(__SAMD10D12AM__) || defined(__ATSAMD10D12AM__)
  #include "samd10d12am.h"
#elif defined(__SAMD10D12AS__) || defined(__ATSAMD10D12AS__)
  #include "samd10d12as.h"
#elif defined(__SAMD10D13AM__) || defined(__ATSAMD10D13AM__)
  #include "samd10d13am.h"
#elif defined(__SAMD10D13AS__) || defined(__ATSAMD10D13AS__)
  #include "samd10d13as.h"
#elif defined(__SAMD10D14AM__) || defined(__ATSAMD10D14AM__)
  #include "samd10d14am.h"
#elif defined(__SAMD10D14AS__) || defined(__ATSAMD10D14AS__)
  #include "samd10d14as.h"
#elif defined(__SAMD10D14AU__) || defined(__ATSAMD10D14AU__)
  #include "samd10d14au.h"
#else
  #error Library does not support the specified device.
#endif

#endif /* _SAMD10_ */

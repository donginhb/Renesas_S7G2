/***********************************************************************************************************************
 * Copyright [2015] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 * 
 * This file is part of Renesas SynergyTM Software Package (SSP)
 *
 * The contents of this file (the "contents") are proprietary and confidential to Renesas Electronics Corporation
 * and/or its licensors ("Renesas") and subject to statutory and contractual protections.
 *
 * This file is subject to a Renesas SSP license agreement. Unless otherwise agreed in an SSP license agreement with
 * Renesas: 1) you may not use, copy, modify, distribute, display, or perform the contents; 2) you may not use any name
 * or mark of Renesas for advertising or publicity purposes or in connection with your use of the contents; 3) RENESAS
 * MAKES NO WARRANTY OR REPRESENTATIONS ABOUT THE SUITABILITY OF THE CONTENTS FOR ANY PURPOSE; THE CONTENTS ARE PROVIDED
 * "AS IS" WITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, AND NON-INFRINGEMENT; AND 4) RENESAS SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, OR
 * CONSEQUENTIAL DAMAGES, INCLUDING DAMAGES RESULTING FROM LOSS OF USE, DATA, OR PROJECTS, WHETHER IN AN ACTION OF
 * CONTRACT OR TORT, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE CONTENTS. Third-party contents
 * included in this file may be subject to different terms.
 **********************************************************************************************************************/
/**********************************************************************************************************************
* File Name    : r_riic.h
* Description  : I2C Bus (RIIC) Module instance header file.
***********************************************************************************************************************/


/*******************************************************************************************************************//**
 * @ingroup HAL_Library
 * @defgroup RIIC IIC
 * @brief Driver for the I2C Bus Interface (IIC).
 *
 * This module supports the Renesas Inter-Integrated Circuit (IIC) peripheral. It implements the following interfaces:
 *   - @ref I2C_API r_i2c_api.h
 * @{
***********************************************************************************************************************/

#ifndef R_RIIC_H
#define R_RIIC_H

#include "bsp_api.h"
#include "r_riic_cfg.h"
#include "r_i2c_api.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define RIIC_MASTER_CODE_VERSION_MAJOR   (1)
#define RIIC_MASTER_CODE_VERSION_MINOR   (1)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/**********************************************************************************************************************
Exported global variables
***********************************************************************************************************************/
/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern i2c_api_master_t const g_i2c_master_on_riic;
/** @endcond */

#endif // R_RIIC_H

/*******************************************************************************************************************//**
 * @} (end defgroup RIIC)
***********************************************************************************************************************/

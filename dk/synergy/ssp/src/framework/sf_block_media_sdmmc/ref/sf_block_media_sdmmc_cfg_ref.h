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
 * File Name    : sf_block_media_sdmmc_cfg_ref.h
 * Description  : SDMMC Block Media for SDMMC configuration file.
 ***********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @ingroup SF_BLOCK_MEDIA_SDMMC
 * @defgroup BLOCK_MEDIA_SDMMC_CFG Build Time Configurations
 * @{
 ***********************************************************************************************************************/

#ifndef SF_BLOCK_MEDIA_SD_CFG_H
#define SF_BLOCK_MEDIA_SD_CFG_H

/**********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/** Specify whether to include code for API parameter checking. Valid settings include:
 *    - BSP_CFG_PARAM_CHECKING_ENABLE : Utilizes the system default setting from bsp_cfg.h
 *    - 1 : Includes parameter checking
 *    - 0 : Compiles out parameter checking
 */
#define BLOCK_MEDIA_SDMMC_CFG_PARAM_CHECKING_ENABLE (BSP_CFG_PARAM_CHECKING_ENABLE)
#endif /* SF_BLOCK_MEDIA_SD_CFG_H */

/*******************************************************************************************************************//**
 * @} (end defgroup SF_BLOCK_MEDIA_SDMMC_CFG)
 ***********************************************************************************************************************/

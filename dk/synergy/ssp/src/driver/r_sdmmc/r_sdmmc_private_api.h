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

#ifndef R_SDMMC_PRIVATE_API_H
#define R_SDMMC_PRIVATE_API_H

/***********************************************************************************************************************
 * Private Instance API Functions. DO NOT USE! Use functions through Interface API structure instead.
 **********************************************************************************************************************/
ssp_err_t R_SDMMC_Open (sdmmc_ctrl_t * const p_ctrl, sdmmc_cfg_t const * const p_cfg);
ssp_err_t R_SDMMC_Close (sdmmc_ctrl_t * const p_ctrl);
ssp_err_t R_SDMMC_Read (sdmmc_ctrl_t * const p_ctrl,
                        uint8_t * const      p_dest,
                        uint32_t const       start_sector,
                        uint32_t const       sector_count);
ssp_err_t R_SDMMC_Write (sdmmc_ctrl_t * const  p_ctrl,
                         uint8_t const * const p_source,
                         uint32_t const        start_sector,
                         uint32_t const        sector_count);

ssp_err_t R_SDMMC_Control (sdmmc_ctrl_t * const p_ctrl,
                            ssp_command_t const command,
                                         void * p_data);

ssp_err_t R_SDMMC_ReadIo (sdmmc_ctrl_t * const p_ctrl,
                              uint8_t * const  p_data,
                               uint32_t const  function,
                               uint32_t const  address);

ssp_err_t R_SDMMC_WriteIo (sdmmc_ctrl_t * const p_ctrl,
                               uint8_t * const  p_data,
                                uint32_t const  function,
                                uint32_t const  address,
                   sdmmc_io_write_mode_t const  read_after_write);

ssp_err_t R_SDMMC_ReadIoExt (sdmmc_ctrl_t * const p_ctrl,
                                  uint8_t * const p_dest,
                                  uint32_t const  function,
                                  uint32_t const  address,
                                uint32_t * const  count,
                        sdmmc_io_transfer_mode_t  transfer_mode,
                         sdmmc_io_address_mode_t  address_mode);

ssp_err_t R_SDMMC_WriteIoExt (sdmmc_ctrl_t * const p_ctrl,
                             uint8_t const * const p_source,
                                   uint32_t const  function,
                                   uint32_t const  address,
                                   uint32_t const  count,
                         sdmmc_io_transfer_mode_t  transfer_mode,
                          sdmmc_io_address_mode_t  address_mode);

ssp_err_t R_SDMMC_IoIntEnable (sdmmc_ctrl_t * const p_ctrl, bool enable);

ssp_err_t R_SDMMC_VersionGet (ssp_version_t * const p_version);

ssp_err_t R_SDMMC_InfoGet (sdmmc_ctrl_t * const p_ctrl,  sdmmc_info_t * const p_info);

ssp_err_t R_SDMMC_Erase (sdmmc_ctrl_t * const p_ctrl,
                               const uint32_t sector_address,
                               const uint32_t sector_count);

#endif /* R_SDMMC_PRIVATE_API_H */

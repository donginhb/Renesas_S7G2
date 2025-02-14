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

#ifndef R_AGT_PRIVATE_API_H
#define R_AGT_PRIVATE_API_H

/***********************************************************************************************************************
 * Private Instance API Functions. DO NOT USE! Use functions through Interface API structure instead.
 **********************************************************************************************************************/
ssp_err_t R_AGT_Close      (timer_ctrl_t * const p_ctrl);
ssp_err_t R_AGT_CounterGet (timer_ctrl_t * const p_ctrl, timer_size_t * const p_value);
ssp_err_t R_AGT_PeriodSet  (timer_ctrl_t * const p_ctrl, timer_size_t const period, timer_unit_t const unit);
ssp_err_t R_AGT_DutyCycleSet (timer_ctrl_t * const p_ctrl, timer_size_t const duty_cycle, timer_pwm_unit_t const unit,
        uint8_t const pin);
ssp_err_t R_AGT_Reset      (timer_ctrl_t * const p_ctrl);
ssp_err_t R_AGT_Start      (timer_ctrl_t * const p_ctrl);
ssp_err_t R_AGT_InfoGet    (timer_ctrl_t * const p_ctrl, timer_info_t * const p_info);
ssp_err_t R_AGT_Stop       (timer_ctrl_t * const p_ctrl);
ssp_err_t R_AGT_TimerOpen  (timer_ctrl_t * const p_ctrl, timer_cfg_t const * const p_cfg);
ssp_err_t R_AGT_VersionGet (ssp_version_t * const p_version);

#endif /* R_AGT_PRIVATE_API_H */

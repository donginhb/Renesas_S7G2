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
 * File Name    : sf_adc_periodic_api.h
 * Description  : RTOS integrated periodic ADC framework.
 **********************************************************************************************************************/

#ifndef SF_ADC_PERIODIC_API_H
#define SF_ADC_PERIODIC_API_H

/*******************************************************************************************************************//**
 * @ingroup SF_Interface_Library
 * @defgroup SF_ADC_PERIODIC_API ADC Periodic Framework Interface
 * @brief RTOS-integrated ADC Periodic Framework Interface
 *
 * @section SF_ADC_PERIODIC_API_SUMMARY Summary
 * This is a ThreadX aware generic Periodic ADC sampling framework intended to be used to sample the ADC at periodic
 * intervals, buffer the specified number of samples and then notify the application. The driver will use hardware
 * triggers to allow for time-synchronous sampling. After initial configuration and the scan process is started, the
 * framework uses a hardware timer to trigger an ADC scan in one-shot mode. Each scan can consist of one or more
 * channels. When each scan is completed the ADC interrupt is intercepted by the DTC which moves the result of the scan
 * into the user buffer. Each scan is defined as a sampling iteration and the number of samples generated for each scan
 * will be equal to the number of channels if the channels are sequential eg: channels 1, 2, 3, 4. If the channels are
 * not in sequence, eg: channels 1, 3, 4, 5, then the samples generated by each scan will also include data from the unused
 * channels in between. Thus the second example here will result in 5 samples being stored to the user buffer each time
 * even though only 4 channels have been configured for usage.
 * The user specifies the total number of sample iterations that need to occur before being notified. When the specified
 * number of sampling iterations have occurred and the data for each iteration has been stored into the user buffer, the
 * user is notified via the callback function with an index for the valid data in the buffer and an event indicating
 * that sampling for the specified number of iterations is complete. Unless the user stops the scan process using the
 * stop API call, the scan will continue to be triggered by the timer and data will be written into the user buffer
 * which is treated by the framework as a circular buffer. For this reason, the buffer length must be at least twice
 * the total number of samples that will be generate after all the iterations are completed. In the second example,
 * where there are 5 samples generated for each iteration, if the sample count is set to 3, this will result in 15
 * samples being available in the buffer before the callback is called. Thus in this example, the buffer length must
 * be set to 30 or larger.
 * The name and length of the buffer is specified via the framework configuration structure.
 *
 * Implemented by:
 * @ref ADC_API
 *
 * Related SSP architecture topics:
 *  - @ref ssp-interfaces
 *  - @ref ssp-predefined-layers
 *  - @ref using-ssp-modules
 *
 * ADC Periodic Framework Interface description: @ref FrameworkADCPeriodicInterface
 *
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_adc_api.h"
#include "r_timer_api.h"
#include "r_transfer_api.h"
#include "r_elc_api.h"
#include "tx_api.h"

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
/** Version of the API defined in this file */
#define SF_ADC_PERIODIC_API_VERSION_MAJOR (1)
#define SF_ADC_PERIODIC_API_VERSION_MINOR (1)

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Options for the callback events. */
typedef enum e_sf_adc_periodic_event
{
    SF_ADC_PERIODIC_EVENT_NEW_DATA,   ///< New data is available in the buffer
} sf_adc_periodic_event_t;

/** ADC callback arguments definitions  */
typedef struct st_sf_adc_periodic_callback_args
{
    sf_adc_periodic_event_t event;        ///< Periodic ADC callback event
    uint32_t                buffer_index; ///< Index to the buffer where the new data is stored.
    void const            * p_context;    ///< Placeholder for user data
} sf_adc_periodic_callback_args_t;

/** Channel control block. DO NOT INITIALIZE.  Initialization occurs when ::SF_ADC_PERIODIC_Open is called */
typedef struct st_sf_adc_periodic_ctrl
{
    uint32_t               open;        ///< Used by driver to check if pointer to control block is valid
    TX_MUTEX               mutex;       ///< Mutex used to protect access to lower level driver hardware registers
    adc_api_t const      * p_api_adc;   ///< Pointer to lower level ADC driver function pointers
    timer_api_t const    * p_api_timer; ///< Pointer to lower level Timer driver function pointers
    transfer_api_t const * p_api_transfer; ///< Pointer to lower level Transfer driver function pointers
    adc_ctrl_t             ctrl_adc;    ///< Lower level ADC driver control block
    timer_ctrl_t           ctrl_timer;  ///< Lower level Timer driver control block
    transfer_ctrl_t        ctrl_transfer;  ///< Lower level Transfer driver control block
    void const * volatile  p_src_transfer;  ///< Source pointer for the low level transfer method
    adc_data_size_t      * p_data_buffer;      ///< Pointer to the buffer that will store the samples
    uint32_t               data_buffer_length; ///< Length of the data buffer that will store the samples
    uint32_t               data_buffer_index;  ///< Index of the data buffer where data is to be written to next
    uint32_t               sample_count;       ///< Samples per channel to be buffered before notifying the app
    uint32_t               dtc_transfer_length;///< Total Length of DTC transfer for requested number of samples
    void                (* p_callback)(sf_adc_periodic_callback_args_t * p_args); ///< Callback function
    void const           * p_context;    ///< Placeholder for user data
} sf_adc_periodic_ctrl_t;

/** Configuration for RTOS integrated ADC driver */
typedef struct st_sf_adc_periodic_cfg
{
    adc_instance_t const * const   p_lower_lvl_adc;   ///< Pointer to the ADC instance
    timer_instance_t const * const p_lower_lvl_timer; ///< Pointer to the Timer instance
    transfer_instance_t const * const p_lower_lvl_transfer; ///< Pointer to the Transfer instance
    adc_data_size_t            * p_data_buffer;       ///< Pointer to the buffer that will store the samples
    uint32_t                     data_buffer_length;  ///< Length of the data buffer that will store the samples
    uint32_t                     sample_count;        ///< Samples per channel to be buffered before notifying the app
    elc_event_t                  scan_trigger;        ///< The hardware trigger that starts the ADC scan
    void                      (* p_callback)(sf_adc_periodic_callback_args_t * p_args); ///< Callback function
    void const                 * p_context;           ///< Placeholder for user data
    void const                 * p_extend;            ///< Extension parameter for hardware specific settings.
} sf_adc_periodic_cfg_t;

/** Framework Periodic ADC API structure.  Implementations will use the following API. */
typedef struct st_sf_adc_periodic_api
{
    /** Acquires mutex, then initializes driver at the HAL layer
     * @param[in,out] p_ctrl   Pointer to a structure allocated by user. Elements initialized here.
     * @param[in]     p_cfg    Pointer to configuration structure. All elements of the structure must be set by user.
     */
    ssp_err_t (* open)(sf_adc_periodic_ctrl_t       * const p_ctrl,
                       sf_adc_periodic_cfg_t  const * const p_cfg);

    /** Starts the scan.
     * @warning The driver will enable the ADC to be triggered via timer event; there will be a time delay from
     * the time this function is called to the time the hardware timer count expires and triggers the scan.
     * @param[in]   p_ctrl     Pointer to control block set in ::SF_ADC_PERIODIC_Open.
     */
    ssp_err_t (* start)(sf_adc_periodic_ctrl_t * const p_ctrl);

    /** Stops the hardware trigger (timer) from triggering any more ADC scans.
     * @param[in]   p_ctrl     Pointer to control block set in ::SF_ADC_PERIODIC_Open.
     */
    ssp_err_t (* stop)(sf_adc_periodic_ctrl_t * const p_ctrl);

    /** Releases channel mutex and closes channel at HAL layer.
     * @param[in]    p_ctrl   Pointer to control block set in ::SF_ADC_PERIODIC_Open.
     */
    ssp_err_t (* close)(sf_adc_periodic_ctrl_t * const p_ctrl);

    /** Gets version and stores it in provided pointer p_version.
     * @param[out]  p_version  Code and API version used.
     */
    ssp_err_t (* versionGet)(ssp_version_t * const p_version);

} sf_adc_periodic_api_t;

/** This structure encompasses everything that is needed to use an instance of this interface. */
typedef struct st_sf_adc_periodic_instance
{
    sf_adc_periodic_ctrl_t      * p_ctrl;    ///< Pointer to the control structure for this instance
    sf_adc_periodic_cfg_t const * p_cfg;     ///< Pointer to the configuration structure for this instance
    sf_adc_periodic_api_t const * p_api;     ///< Pointer to the API structure for this instance
} sf_adc_periodic_instance_t;

/*******************************************************************************************************************//**
 * @} (end defgroup SF_ADC_PERIODIC_API)
 **********************************************************************************************************************/
 
#endif /* SF_ADC_PERIODIC_API_H */

/* generated main source file - do not edit */
#include "bsp_api.h"
#include "tx_api.h"

extern void dev_example_thread_create(void);
extern void sf_audio_playback_demo_thread_create(void);
extern void sf_adc_demo_thread_create(void);
extern void sf_i2c_pcal1_thread_create(void);
extern void sf_i2c_pcal2_thread_create(void);
extern void r_wdt_demo_thread_create(void);
extern void sf_thread_monitor_demo_thread_create(void);
extern void sf_el_nx_comms_demo_thread_create(void);
extern void sf_touch_panel_demo_thread_create(void);

void g_hal_init(void);

#if defined(__ICCARM__)
#define WEAK_REF_ATTRIBUTE
#pragma weak tx_application_define_user               = tx_application_define_internal
#elif defined(__GNUC__)
#define WEAK_REF_ATTRIBUTE      __attribute__ ((weak, alias("tx_application_define_internal")))
#endif

#ifdef TX_USER_TRACE_BUFFER_DECLARE
TX_USER_TRACE_BUFFER_DECLARE;
#endif

void tx_application_define_internal(void * first_unused_memory);

void tx_application_define_internal(void * first_unused_memory)
{
    /* Does nothing. Default implementation of tx_application_define_user(). */
    SSP_PARAMETER_NOT_USED (first_unused_memory);
}

void tx_application_define_internal(void * first_unused_memory);
void tx_application_define_user(void * first_unused_memory)
WEAK_REF_ATTRIBUTE;

void tx_application_define(void * first_unused_memory)
{
    dev_example_thread_create ();
    sf_audio_playback_demo_thread_create ();
    sf_adc_demo_thread_create ();
    sf_i2c_pcal1_thread_create ();
    sf_i2c_pcal2_thread_create ();
    r_wdt_demo_thread_create ();
    sf_thread_monitor_demo_thread_create ();
    sf_el_nx_comms_demo_thread_create ();
    sf_touch_panel_demo_thread_create ();

#ifdef TX_USER_ENABLE_TRACE
    TX_USER_ENABLE_TRACE;
#endif

    g_hal_init ();

    tx_application_define_user (first_unused_memory);
}

int main(void)
{
    __disable_irq ();
    tx_kernel_enter ();

    return 0;
}

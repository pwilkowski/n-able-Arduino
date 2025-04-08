/*
 * FreeRTOS Kernel V10.4.3
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <assert.h>

/*-----------------------------------------------------------
 * Possible configurations for system timer
 */
#define FREERTOS_USE_RTC      0 /**< Use real time clock for the system */
#define FREERTOS_USE_SYSTICK  1 /**< Use SysTick timer for system */

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/
#ifndef CONFIG_RTOS_TICK_RATE_HZ
#define CONFIG_RTOS_TICK_RATE_HZ       (1024)
#endif

#if defined(DEVICE_RAM_SIZE)
#  if DEVICE_RAM_SIZE < 32
#    ifndef CONFIG_RTOS_MAX_PRIORITIES
#      define CONFIG_RTOS_MAX_PRIORITIES (3)
#    endif
#    ifndef CONFIG_RTOS_MIN_TASK_STACK_SIZE
#      define CONFIG_RTOS_MIN_TASK_STACK_SIZE (48)
#    endif
#    ifndef CONFIG_RTOS_TIMER_QUEUE_LENGTH
#      define CONFIG_RTOS_TIMER_QUEUE_LENGTH (6)
#    endif
#    ifndef CONFIG_RTOS_TIMER_STACK_DEPTH
#      define CONFIG_RTOS_TIMER_STACK_DEPTH (72)
#    endif
#  endif
#endif

#ifndef CONFIG_RTOS_MAX_PRIORITIES
#define CONFIG_RTOS_MAX_PRIORITIES (5)
#endif

#ifndef CONFIG_RTOS_MIN_TASK_STACK_SIZE
#define CONFIG_RTOS_MIN_TASK_STACK_SIZE (120)
#endif

#ifndef CONFIG_RTOS_TIMER_QUEUE_LENGTH
#define CONFIG_RTOS_TIMER_QUEUE_LENGTH (32)
#endif

#ifndef CONFIG_RTOS_TIMER_STACK_DEPTH
#define CONFIG_RTOS_TIMER_STACK_DEPTH (256)
#endif

#ifndef CONFIG_RTOS_USE_TRACE_FACILITY
#define CONFIG_RTOS_USE_TRACE_FACILITY (0)
#endif

#ifndef CONFIG_RTOS_USE_STATS_FORMATTING_FUNCTIONS
#define CONFIG_RTOS_USE_STATS_FORMATTING_FUNCTIONS (0)
#endif


#define configTICK_SOURCE                                                         FREERTOS_USE_RTC

#define configUSE_PREEMPTION                                                      1
#ifdef NRF51
#define configUSE_PORT_OPTIMISED_TASK_SELECTION                                   0
#else
#define configUSE_PORT_OPTIMISED_TASK_SELECTION                                   1
#endif
#define configUSE_TICKLESS_IDLE                                                   1
#define configUSE_TICKLESS_IDLE_SIMPLE_DEBUG                                      1 /* See into vPortSuppressTicksAndSleep source code for explanation */
#define configCPU_CLOCK_HZ                                                        ( SystemCoreClock )
#define configTICK_RATE_HZ                                                        CONFIG_RTOS_TICK_RATE_HZ
#define configMAX_PRIORITIES                                                      CONFIG_RTOS_MAX_PRIORITIES
#define configMINIMAL_STACK_SIZE                                                  CONFIG_RTOS_MIN_TASK_STACK_SIZE
#define configTOTAL_HEAP_SIZE                                                     ( 4096 ) //unused - modified heap_4 uses remaining available RAM
#define configMAX_TASK_NAME_LEN                                                   ( 4 )
#define configUSE_16_BIT_TICKS                                                    0
#define configIDLE_SHOULD_YIELD                                                   1
#define configUSE_MUTEXES                                                         1
#define configUSE_RECURSIVE_MUTEXES                                               1
#define configUSE_COUNTING_SEMAPHORES                                             1
#define configUSE_ALTERNATIVE_API                                                 0    /* Deprecated! */
#define configQUEUE_REGISTRY_SIZE                                                 0
#define configUSE_QUEUE_SETS                                                      0
#define configUSE_TIME_SLICING                                                    0
#define configUSE_NEWLIB_REENTRANT                                                0
#define configENABLE_BACKWARD_COMPATIBILITY                                       1
#define configSUPPORT_STATIC_ALLOCATION                                           1

/* Hook function related definitions. */
#define configUSE_IDLE_HOOK                                                       1
#define configUSE_TICK_HOOK                                                       0
#define configCHECK_FOR_STACK_OVERFLOW                                            2
#define configUSE_MALLOC_FAILED_HOOK                                              1

/* Run time and task stats gathering related definitions. */
#define configGENERATE_RUN_TIME_STATS                                             0
#define configUSE_TRACE_FACILITY                                                  CONFIG_RTOS_USE_TRACE_FACILITY
#define configUSE_STATS_FORMATTING_FUNCTIONS                                      CONFIG_RTOS_USE_STATS_FORMATTING_FUNCTIONS

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES                                                     0
#define configMAX_CO_ROUTINE_PRIORITIES                                           ( 2 )

/* Software timer definitions. */
#define configUSE_TIMERS                                                          1
#define configTIMER_TASK_PRIORITY                                                 ( configMAX_PRIORITIES - 1)
#define configTIMER_QUEUE_LENGTH                                                  CONFIG_RTOS_TIMER_QUEUE_LENGTH
#define configTIMER_TASK_STACK_DEPTH                                              CONFIG_RTOS_TIMER_STACK_DEPTH

/* Tickless Idle configuration. */
#define configEXPECTED_IDLE_TIME_BEFORE_SLEEP                                     2

/* Tickless idle/low power functionality. */

/* Define to trap errors during development. */
#if defined(CONFIG_RTOS_DEBUG)
#define configASSERT( x )                                                         assert(x)
#endif

/* FreeRTOS MPU specific definitions. */
#define configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS                    1

/* Optional functions - most linkers will remove unused functions anyway. */
#define INCLUDE_vTaskPrioritySet                                                  1
#define INCLUDE_uxTaskPriorityGet                                                 1
#define INCLUDE_vTaskDelete                                                       1
#define INCLUDE_vTaskSuspend                                                      1
#define INCLUDE_xResumeFromISR                                                    1
#define INCLUDE_vTaskDelayUntil                                                   1
#define INCLUDE_vTaskDelay                                                        1
#define INCLUDE_xTaskGetSchedulerState                                            1
#define INCLUDE_xTaskGetCurrentTaskHandle                                         1
#define INCLUDE_uxTaskGetStackHighWaterMark                                       1
#define INCLUDE_xTaskGetIdleTaskHandle                                            1
#define INCLUDE_xTimerGetTimerDaemonTaskHandle                                    1
#define INCLUDE_pcTaskGetTaskName                                                 1
#define INCLUDE_eTaskGetState                                                     1
#define INCLUDE_xEventGroupSetBitFromISR                                          1
#define INCLUDE_xTimerPendFunctionCall                                            1

/* Code below should be only used by the compiler, and not the assembler. */
#if !(defined(__ASSEMBLY__) || defined(__ASSEMBLER__))
    #include "nrf.h"
    #define ASSERT(expr)

    /* This part of definitions may be problematic in assembly - it uses definitions from files that are not assembly compatible. */
    /* Cortex-M specific definitions. */
    #ifdef __NVIC_PRIO_BITS
        /* __BVIC_PRIO_BITS will be specified when CMSIS is being used. */
        #define configPRIO_BITS             __NVIC_PRIO_BITS
    #else
        #error "This port requires __NVIC_PRIO_BITS to be defined"
    #endif

    /* Access to current system core clock is required only if we are ticking the system by systimer */
    #if (configTICK_SOURCE == FREERTOS_USE_SYSTICK)
        #include <stdint.h>
        extern uint32_t SystemCoreClock;
    #endif
#endif /* !assembler */

/* The lowest interrupt priority that can be used in a call to a "set priority"
function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         ( ( 1 << configPRIO_BITS ) - 1 )

/* The highest interrupt priority that can be used by any interrupt service
routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
PRIORITY THAN THIS! (higher priorities are lower numeric values. */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    2

/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY                 configLIBRARY_LOWEST_INTERRUPT_PRIORITY
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY            configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names - or at least those used in the unmodified vector table. */

#define vPortSVCHandler                                                           SVC_Handler
#define xPortPendSVHandler                                                        PendSV_Handler


/*-----------------------------------------------------------
 * Settings that are generated automatically
 * basing on the settings above
 */
#if (configTICK_SOURCE == FREERTOS_USE_SYSTICK)
    // do not define configSYSTICK_CLOCK_HZ for SysTick to be configured automatically
    // to CPU clock source
    #define xPortSysTickHandler     SysTick_Handler
#elif (configTICK_SOURCE == FREERTOS_USE_RTC)
    #define configSYSTICK_CLOCK_HZ  ( 32768UL )
    #define xPortSysTickHandler     RTC1_IRQHandler
#else
    #error  Unsupported configTICK_SOURCE value
#endif

/** Implementation note:  Use this with caution and set this to 1 ONLY for debugging
 * ----------------------------------------------------------
     * Set the value of configUSE_DISABLE_TICK_AUTO_CORRECTION_DEBUG to below for enabling or disabling RTOS tick auto correction:
     * 0. This is default. If the RTC tick interrupt is masked for more than 1 tick by higher priority interrupts, then most likely
     *    one or more RTC ticks are lost. The tick interrupt inside RTOS will detect this and make a correction needed. This is needed
     *    for the RTOS internal timers to be more accurate.
     * 1. The auto correction for RTOS tick is disabled even though few RTC tick interrupts were lost. This feature is desirable when debugging
     *    the RTOS application and stepping though the code. After stepping when the application is continued in debug mode, the auto-corrections of
     *    RTOS tick might cause asserts. Setting configUSE_DISABLE_TICK_AUTO_CORRECTION_DEBUG to 1 will make RTC and RTOS go out of sync but could be
     *    convenient for debugging.
     */
#define configUSE_DISABLE_TICK_AUTO_CORRECTION_DEBUG     0

#endif /* FREERTOS_CONFIG_H */

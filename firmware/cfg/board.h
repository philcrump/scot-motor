/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for Phil Crump's SCOT Resolver Interface board.
 */

/*
 * Board identifier.
 */
#define BOARD_SCOT_RESOLVER_rFeb2020
#define BOARD_NAME                  "SCOT Resolver Interface - Feb 2020"

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 * NOTE: HSE 8MHz 10ppm XTAL fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0U
#endif

#define STM32_LSEDRV                (3U << 3U)

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                8000000U
#endif

/*
 * MCU type as defined in the ST header.
 */
#define STM32F042x6

/*
 * IO pins assignments.
 */
#define GPIOA_PIN0                  0U
#define GPIOA_PIN1                  1U
#define GPIOA_UART_TX               2U
#define GPIOA_UART_RX               3U
#define GPIOA_LIMIT_1               4U
#define GPIOA_LIMIT_2               5U
#define GPIOA_PWM_nFAULT            6U
#define GPIOA_CONTROL_OK            7U
#define GPIOA_PWM_CH1               8U
#define GPIOA_PWM_CH2               9U
#define GPIOA_PIN10                 10U
#define GPIOA_CAN_RX                11U
#define GPIOA_CAN_TX                12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_PIN15                 15U

#define GPIOB_PIN0                  0U
#define GPIOB_PIN1                  1U
//#define GPIOB_PIN2                  2U
#define GPIOB_nBRAKE                3U
#define GPIOB_PIN4                  4U
#define GPIOB_VI_ALERT              5U
#define GPIOB_VI_SCL                6U
#define GPIOB_VI_SDA                7U
#define GPIOB_BOOT0                 8U

#define GPIOF_OSC_IN                0U
#define GPIOF_OSC_OUT               1U

/*
 * IO lines assignments.
 */
#define LINE_LIMIT_1                PAL_LINE(GPIOA, GPIOA_LIMIT_1)
#define LINE_LIMIT_2                PAL_LINE(GPIOA, GPIOA_LIMIT_2)
#define LINE_PWM_nFAULT             PAL_LINE(GPIOA, GPIOA_PWM_nFAULT)
#define LINE_CONTROL_OK             PAL_LINE(GPIOA, GPIOA_CONTROL_OK)

#define LINE_nBRAKE                 PAL_LINE(GPIOB, GPIOB_nBRAKE)
#define LINE_VI_ALERT               PAL_LINE(GPIOB, GPIOB_VI_ALERT)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))

/*
 * GPIOA setup:
 *
*/

#define VAL_GPIOA_MODER             (PIN_MODE_ANALOG(GPIOA_PIN0) |    \
                                     PIN_MODE_ANALOG(GPIOA_PIN1) |       \
                                     PIN_MODE_ALTERNATE(GPIOA_UART_TX) |       \
                                     PIN_MODE_ALTERNATE(GPIOA_UART_RX) |         \
                                     PIN_MODE_INPUT(GPIOA_LIMIT_1) |         \
                                     PIN_MODE_INPUT(GPIOA_LIMIT_2) |        \
                                     PIN_MODE_INPUT(GPIOA_PWM_nFAULT) |        \
                                     PIN_MODE_OUTPUT(GPIOA_CONTROL_OK) |          \
                                     PIN_MODE_ALTERNATE(GPIOA_PWM_CH1) |          \
                                     PIN_MODE_ALTERNATE(GPIOA_PWM_CH2) |    \
                                     PIN_MODE_ANALOG(GPIOA_PIN10) |    \
                                     PIN_MODE_ALTERNATE(GPIOA_CAN_RX) |     \
                                     PIN_MODE_ALTERNATE(GPIOA_CAN_TX) |     \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK) |      \
                                     PIN_MODE_OUTPUT(GPIOA_PIN15))

#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_PIN0) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN1) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_UART_TX) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_UART_RX) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_LIMIT_1) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_LIMIT_2) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PWM_nFAULT) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_CONTROL_OK) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PWM_CH1) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PWM_CH2) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN10) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_CAN_RX) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOA_CAN_TX) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN15))

#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOA_PIN0) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN1) |        \
                                     PIN_OSPEED_HIGH(GPIOA_UART_TX) |         \
                                     PIN_OSPEED_HIGH(GPIOA_UART_RX) |         \
                                     PIN_OSPEED_VERYLOW(GPIOA_LIMIT_1) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_LIMIT_2) |         \
                                     PIN_OSPEED_VERYLOW(GPIOA_PWM_nFAULT) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_CONTROL_OK) |        \
                                     PIN_OSPEED_HIGH(GPIOA_PWM_CH1) |        \
                                     PIN_OSPEED_HIGH(GPIOA_PWM_CH2) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN10) |        \
                                     PIN_OSPEED_HIGH(GPIOA_CAN_RX) |       \
                                     PIN_OSPEED_HIGH(GPIOA_CAN_TX) |        \
                                     PIN_OSPEED_HIGH(GPIOA_SWDIO) |         \
                                     PIN_OSPEED_HIGH(GPIOA_SWCLK) |         \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN15))

#define VAL_GPIOA_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOA_PIN0) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOA_PIN1) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOA_UART_TX) |     \
                                     PIN_PUPDR_PULLDOWN(GPIOA_UART_RX) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOA_LIMIT_1) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOA_LIMIT_2) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOA_PWM_nFAULT) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOA_CONTROL_OK) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOA_PWM_CH1) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOA_PWM_CH2) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOA_PIN10) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_CAN_RX) |      \
                                     PIN_PUPDR_FLOATING(GPIOA_CAN_TX) |       \
                                     PIN_PUPDR_PULLUP(GPIOA_SWDIO) |        \
                                     PIN_PUPDR_PULLDOWN(GPIOA_SWCLK) |      \
                                     PIN_PUPDR_PULLDOWN(GPIOA_PIN15))

#define VAL_GPIOA_ODR               (PIN_ODR_LOW(GPIOA_PIN0) |           \
                                     PIN_ODR_LOW(GPIOA_PIN1) |           \
                                     PIN_ODR_LOW(GPIOA_UART_TX) |           \
                                     PIN_ODR_LOW(GPIOA_UART_RX) |           \
                                     PIN_ODR_LOW(GPIOA_LIMIT_1) |           \
                                     PIN_ODR_LOW(GPIOA_LIMIT_2) |            \
                                     PIN_ODR_LOW(GPIOA_PWM_nFAULT) |           \
                                     PIN_ODR_LOW(GPIOA_CONTROL_OK) |           \
                                     PIN_ODR_LOW(GPIOA_PWM_CH1) |           \
                                     PIN_ODR_LOW(GPIOA_PWM_CH2) |           \
                                     PIN_ODR_LOW(GPIOA_PIN10) |           \
                                     PIN_ODR_LOW(GPIOA_CAN_RX) |          \
                                     PIN_ODR_LOW(GPIOA_CAN_TX) |           \
                                     PIN_ODR_HIGH(GPIOA_SWDIO) |            \
                                     PIN_ODR_HIGH(GPIOA_SWCLK) |            \
                                     PIN_ODR_LOW(GPIOA_PIN15))

#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_PIN0, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_PIN1, 0U) |           \
                                     PIN_AFIO_AF(GPIOA_UART_TX, 1U) |        \
                                     PIN_AFIO_AF(GPIOA_UART_RX, 1U) |        \
                                     PIN_AFIO_AF(GPIOA_LIMIT_1, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_LIMIT_2, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_PWM_nFAULT, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_CONTROL_OK, 0U))

#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_PWM_CH1, 2U) |        \
                                     PIN_AFIO_AF(GPIOA_PWM_CH2, 2U) |        \
                                     PIN_AFIO_AF(GPIOA_PIN10, 0U) |        \
                                     PIN_AFIO_AF(GPIOA_CAN_RX, 4U) |       \
                                     PIN_AFIO_AF(GPIOA_CAN_TX, 4U) |        \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_PIN15, 0U))

/*
 * GPIOB setup:
 *
*/

#define VAL_GPIOB_MODER             (PIN_MODE_ANALOG(GPIOB_PIN0) |         \
                                     PIN_MODE_ANALOG(GPIOB_PIN1) |         \
                                     PIN_MODE_OUTPUT(GPIOB_nBRAKE) |           \
                                     PIN_MODE_ANALOG(GPIOB_PIN4) |       \
                                     PIN_MODE_INPUT(GPIOB_VI_ALERT) |        \
                                     PIN_MODE_ALTERNATE(GPIOB_VI_SCL) |        \
                                     PIN_MODE_ALTERNATE(GPIOB_VI_SDA) |         \
                                     PIN_MODE_INPUT(GPIOB_BOOT0))

#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_PIN0) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN1) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOB_nBRAKE) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN4) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOB_VI_ALERT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOB_VI_SCL) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOB_VI_SDA) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOB_BOOT0))

#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOB_PIN0) |        \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN1) |        \
                                     PIN_OSPEED_VERYLOW(GPIOB_nBRAKE) |          \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN4) |       \
                                     PIN_OSPEED_LOW(GPIOB_VI_ALERT) |       \
                                     PIN_OSPEED_LOW(GPIOB_VI_SCL) |       \
                                     PIN_OSPEED_HIGH(GPIOB_VI_SDA) |        \
                                     PIN_OSPEED_HIGH(GPIOB_BOOT0))

#define VAL_GPIOB_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOB_PIN0) |       \
                                     PIN_PUPDR_PULLDOWN(GPIOB_PIN1) |       \
                                     PIN_PUPDR_PULLUP(GPIOB_nBRAKE) |         \
                                     PIN_PUPDR_PULLDOWN(GPIOB_PIN4) |    \
                                     PIN_PUPDR_PULLDOWN(GPIOB_VI_ALERT) |      \
                                     PIN_PUPDR_PULLUP(GPIOB_VI_SCL) |      \
                                     PIN_PUPDR_PULLUP(GPIOB_VI_SDA) |       \
                                     PIN_PUPDR_PULLUP(GPIOB_BOOT0))

#define VAL_GPIOB_ODR               (PIN_ODR_HIGH(GPIOB_PIN0) |           \
                                     PIN_ODR_HIGH(GPIOB_PIN1) |           \
                                     PIN_ODR_LOW(GPIOB_nBRAKE) |             \
                                     PIN_ODR_HIGH(GPIOB_PIN4) |           \
                                     PIN_ODR_HIGH(GPIOB_VI_ALERT) |          \
                                     PIN_ODR_HIGH(GPIOB_VI_SCL) |          \
                                     PIN_ODR_HIGH(GPIOB_VI_SDA) |           \
                                     PIN_ODR_HIGH(GPIOB_BOOT0))

#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_PIN0, 0U) |        \
                                     PIN_AFIO_AF(GPIOB_PIN1, 0U) |        \
                                     PIN_AFIO_AF(GPIOB_nBRAKE, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_PIN4, 0U) |       \
                                     PIN_AFIO_AF(GPIOB_VI_ALERT, 0U) |       \
                                     PIN_AFIO_AF(GPIOB_VI_SCL, 1U) |       \
                                     PIN_AFIO_AF(GPIOB_VI_SDA, 1U))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_BOOT0, 0U))


#define VAL_GPIOF_MODER             (PIN_MODE_INPUT(GPIOF_OSC_IN) |         \
                                     PIN_MODE_INPUT(GPIOF_OSC_OUT))

#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOF_OSC_IN) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOF_OSC_OUT))

#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_HIGH(GPIOF_OSC_IN) |        \
                                     PIN_OSPEED_HIGH(GPIOF_OSC_OUT))

#define VAL_GPIOF_PUPDR             (PIN_PUPDR_PULLUP(GPIOF_OSC_IN) |       \
                                     PIN_PUPDR_PULLUP(GPIOF_OSC_OUT))

#define VAL_GPIOF_ODR               (PIN_ODR_HIGH(GPIOF_OSC_IN) |           \
                                     PIN_ODR_HIGH(GPIOF_OSC_OUT))

#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIOF_OSC_IN, 0U) |        \
                                     PIN_AFIO_AF(GPIOF_OSC_OUT, 0U))
#define VAL_GPIOF_AFRH              ( 0x00 )

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */

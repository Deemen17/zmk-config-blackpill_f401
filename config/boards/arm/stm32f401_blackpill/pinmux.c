/*
 * Copyright (c) 2016 Linaro Limited.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <drivers/pinmux.h>
#include <sys/sys_io.h>

#include <pinmux/stm32/pinmux_stm32.h>
#include <pinmux/stm32/pinmux_stm32f4.h>

/* pin assignments for STM32F4DISCOVERY board */

/*

https://github.com/intel/zephyr/blob/master/drivers/pinmux/stm32/pinmux_stm32f4.h

*/
static const struct pin_config pinconf[] = {

#ifdef CONFIG_UART_1
    {STM32_PIN_PA9, STM32F3_PINMUX_FUNC_PA9_USART1_TX},
    {STM32_PIN_PA10, STM32F3_PINMUX_FUNC_PA10_USART1_RX},
#endif /* CONFIG_UART_1 */
#ifdef CONFIG_UART_2
    {STM32_PIN_PA2, STM32F3_PINMUX_FUNC_PA2_USART2_TX},
    {STM32_PIN_PA3, STM32F3_PINMUX_FUNC_PA3_USART2_RX},
#endif /* CONFIG_UART_2 */
#ifdef CONFIG_I2C_1
    {STM32_PIN_PB6, STM32F3_PINMUX_FUNC_PB6_I2C1_SCL},
    {STM32_PIN_PB7, STM32F3_PINMUX_FUNC_PB7_I2C1_SDA},
#endif /* CONFIG_I2C_1 */
#ifdef CONFIG_I2C_2
    {STM32_PIN_PB10, STM32F3_PINMUX_FUNC_PA9_I2C2_SCL},
    {STM32_PIN_PB11, STM32F3_PINMUX_FUNC_PA10_I2C2_SDA},
#endif /* CONFIG_I2C_2 */
#ifdef CONFIG_SPI_1
#ifdef CONFIG_SPI_STM32_USE_HW_SS
    {STM32_PIN_PA4, STM32F3_PINMUX_FUNC_PA4_SPI1_NSS},
#endif /* CONFIG_SPI_STM32_USE_HW_SS */
    {STM32_PIN_PA5, STM32F3_PINMUX_FUNC_PA5_SPI1_SCK},
    {STM32_PIN_PA6, STM32F3_PINMUX_FUNC_PA6_SPI1_MISO},
    {STM32_PIN_PA7, STM32F3_PINMUX_FUNC_PA7_SPI1_MOSI},
#endif /* CONFIG_SPI_1 */
#ifdef CONFIG_SPI_2
#ifdef CONFIG_SPI_STM32_USE_HW_SS
    {STM32_PIN_PB12, STM32F3_PINMUX_FUNC_PB12_SPI2_NSS},
#endif /* CONFIG_SPI_STM32_USE_HW_SS */
    {STM32_PIN_PB13, STM32F3_PINMUX_FUNC_PB13_SPI2_SCK},
    {STM32_PIN_PB14, STM32F3_PINMUX_FUNC_PB14_SPI2_MISO},
    {STM32_PIN_PB15, STM32F3_PINMUX_FUNC_PB15_SPI2_MOSI},
#endif /* CONFIG_SPI_2 */
#ifdef CONFIG_USB_DC_STM32
    {STM32_PIN_PA11, STM32F3_PINMUX_FUNC_PA11_USB_DM},
    {STM32_PIN_PA12, STM32F3_PINMUX_FUNC_PA12_USB_DP},
#endif /* CONFIG_USB_DC_STM32 */
#ifdef CONFIG_CAN_1
    {STM32_PIN_PD0, STM32F3_PINMUX_FUNC_PD0_CAN1_RX},
    {STM32_PIN_PD1, STM32F3_PINMUX_FUNC_PD1_CAN1_TX},
#endif /* CONFIG_CAN_1 */

/*
#if DT_NODE_HAS_STATUS(DT_NODELABEL(usart1), okay) && CONFIG_SERIAL
	{STM32_PIN_PB6, STM32F4_PINMUX_FUNC_PB6_USART1_TX},
	{STM32_PIN_PB7, STM32F4_PINMUX_FUNC_PB7_USART1_RX},
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(usart2), okay) && CONFIG_SERIAL
	{STM32_PIN_PA2, STM32F4_PINMUX_FUNC_PA2_USART2_TX},
	{STM32_PIN_PA3, STM32F4_PINMUX_FUNC_PA3_USART2_RX},
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(pwm2), okay) && CONFIG_PWM
	{STM32_PIN_PA0, STM32F4_PINMUX_FUNC_PA0_PWM2_CH1},
#endif
#ifdef CONFIG_USB_DC_STM32
	{STM32_PIN_PA11, STM32F4_PINMUX_FUNC_PA11_OTG_FS_DM},
	{STM32_PIN_PA12, STM32F4_PINMUX_FUNC_PA12_OTG_FS_DP},
#endif	/* CONFIG_USB_DC_STM32 */
/*
#if DT_NODE_HAS_STATUS(DT_NODELABEL(can1), okay) && CONFIG_CAN
	{STM32_PIN_PB8, STM32F4_PINMUX_FUNC_PB8_CAN1_RX},
	{STM32_PIN_PB9, STM32F4_PINMUX_FUNC_PB9_CAN1_TX},
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(can2), okay) && CONFIG_CAN
	{STM32_PIN_PB5, STM32F4_PINMUX_FUNC_PB5_CAN2_RX},
	{STM32_PIN_PB13, STM32F4_PINMUX_FUNC_PB13_CAN2_TX},
#endif
*/


};

static int pinmux_stm32_init(const struct device *port)
{
	ARG_UNUSED(port);

	stm32_setup_pins(pinconf, ARRAY_SIZE(pinconf));

	return 0;
}

SYS_INIT(pinmux_stm32_init, PRE_KERNEL_1,
		CONFIG_PINMUX_STM32_DEVICE_INITIALIZATION_PRIORITY);

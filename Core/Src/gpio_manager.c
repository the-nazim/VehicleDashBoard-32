/*
 * gpio_manager.c
 *
 *  Created on: Jul 30, 2026
 *      Author: nazim
 */

#include "gpio_manager.h"

bool GPIO_Ignition(void)
{
    return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==GPIO_PIN_RESET;
}

bool GPIO_HeadLight(void)
{
    return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)==GPIO_PIN_RESET;
}

bool GPIO_Door(void)
{
    return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10)==GPIO_PIN_RESET;
}

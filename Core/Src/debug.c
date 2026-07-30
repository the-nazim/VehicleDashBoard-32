/*
 * debug.c
 *
 *  Created on: Jul 27, 2026
 *      Author: nazim
 */

#include "debug.h"
#include <string.h>

extern UART_HandleTypeDef huart1;

void Debug_Print(char *msg)
{
    HAL_UART_Transmit(
        &huart1,
        (uint8_t*)msg,
        strlen(msg),
        HAL_MAX_DELAY);
}

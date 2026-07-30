/*
 * debug.c
 *
 *  Created on: Jul 27, 2026
 *      Author: nazim
 */

#include "uart_manager.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

extern UART_HandleTypeDef huart1;

void UART_Print(char *str)
{
    HAL_UART_Transmit(&huart1,
                      (uint8_t*)str,
                      strlen(str),
                      HAL_MAX_DELAY);
}

void UART_Printf(char *format,...)
{
    char buffer[200];
    va_list args;

    va_start(args,format);

    vsprintf(buffer,format,args);

    va_end(args);

    UART_Print(buffer);
}

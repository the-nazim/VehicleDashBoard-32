/*
 * diagnostics.c
 *
 *  Created on: Jul 30, 2026
 *      Author: nazim
 */

#include "diagnostics.h"
#include "vehicle.h"
#include "uart_manager.h"

void Diagnostics_Run(void)
{
    if(Vehicle.fuel<10)
    {
        UART_Printf("WARNING : LOW FUEL\r\n");
    }

    if(Vehicle.battery<11.5)
    {
        UART_Printf("WARNING : LOW BATTERY\r\n");
    }

    if(Vehicle.door && Vehicle.speed>0)
    {
        UART_Printf("WARNING : DOOR OPEN\r\n");
    }
}

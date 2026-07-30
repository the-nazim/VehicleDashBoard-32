/*
 * dashboard.c
 *
 *  Created on: Jul 30, 2026
 *      Author: nazim
 */

#include "dashboard.h"
#include "vehicle.h"
#include "uart_manager.h"

void Dashboard_Print(void)
{
    UART_Printf("\r\n");

    UART_Printf("-----------------------------\r\n");

    UART_Printf("Vehicle ECU\r\n");

    UART_Printf("-----------------------------\r\n");

    UART_Printf("Speed      : %d km/h\r\n",Vehicle.speed);

    UART_Printf("RPM        : %d\r\n",Vehicle.rpm);

    UART_Printf("Fuel       : %d %%\r\n",Vehicle.fuel);

    UART_Printf("Battery    : %.2f V\r\n",Vehicle.battery);

    UART_Printf("Ignition   : %s\r\n",
            Vehicle.ignition?"ON":"OFF");

    UART_Printf("HeadLight  : %s\r\n",
            Vehicle.headlights?"ON":"OFF");

    UART_Printf("Door       : %s\r\n",
            Vehicle.door?"OPEN":"CLOSED");

    UART_Printf("-----------------------------\r\n");
}

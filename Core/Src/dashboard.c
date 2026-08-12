/*
 * dashboard.c
 *
 *  Created on: Jul 30, 2026
 *      Author: nazim
 */

#include "dashboard.h"
#include "vehicle.h"
#include "uart_manager.h"
#include "ssd1306.h"

#include <stdio.h>

void Dashboard_Print(void)
{
	char buffer[32];

    /* =========================================================
     * UART DASHBOARD
     * ========================================================= */

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


    /* =========================================================
     * SSD1306 DASHBOARD
     * ========================================================= */

    SSD1306_Fill(SSD1306_COLOR_BLACK);


    /* Title */

    SSD1306_GotoXY(0, 0);

    SSD1306_Puts("VEHICLE ECU");


    /* Speed */

    SSD1306_GotoXY(0, 8);

    sprintf(
        buffer,
        "SPD: %d KM/H",
        Vehicle.speed
    );

    SSD1306_Puts(buffer);


    /* RPM */

    SSD1306_GotoXY(0, 16);

    sprintf(
        buffer,
        "RPM: %d",
        Vehicle.rpm
    );

    SSD1306_Puts(buffer);


    /* Fuel */

    SSD1306_GotoXY(0, 24);

    sprintf(
        buffer,
        "FUEL: %d%%",
        Vehicle.fuel
    );

    SSD1306_Puts(buffer);


    /* Battery */

    SSD1306_GotoXY(0, 32);

    sprintf(buffer, "BAT: %.2f V", Vehicle.battery);

    SSD1306_Puts(buffer);


    /* Ignition */

    SSD1306_GotoXY(0, 40);

    if (Vehicle.ignition)
    {
        SSD1306_Puts("IGN: ON");
    }
    else
    {
        SSD1306_Puts("IGN: OFF");
    }

    /* Headlight */

    SSD1306_GotoXY(0, 48);

    if (Vehicle.headlights)
    {
        SSD1306_Puts("LIGHT: ON");
    }
    else
    {
        SSD1306_Puts("LIGHT: OFF");
    }

    /* Send framebuffer to display */

    SSD1306_UpdateScreen();
}

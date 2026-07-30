/*
 * vehicle.c
 *
 *  Created on: Jul 30, 2026
 *      Author: nazim
 */

#include "vehicle.h"
#include "adc_manager.h"
#include "gpio_manager.h"

Vehicle_t Vehicle;

void Vehicle_Init(void)
{
    Vehicle.speed=0;
    Vehicle.rpm=0;
    Vehicle.fuel=0;
    Vehicle.battery=0;
}

void Vehicle_Update(void)
{
    ADC_Manager_Update();

    Vehicle.speed=ADC_GetSpeed();

    Vehicle.fuel=ADC_GetFuel();

    Vehicle.battery=ADC_GetBatteryVoltage();

    Vehicle.ignition=GPIO_Ignition();

    Vehicle.headlights=GPIO_HeadLight();

    Vehicle.door=GPIO_Door();

    Vehicle.rpm=Vehicle.speed*35;
}

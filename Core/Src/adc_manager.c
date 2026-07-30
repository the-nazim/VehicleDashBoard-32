/*
 * adc_manager.c
 *
 *  Created on: Jul 30, 2026
 *      Author: nazim
 */

#include "adc_manager.h"

extern ADC_HandleTypeDef hadc1;

static uint16_t adcValue[ADC_COUNT];

void ADC_Manager_Update(void)
{
    HAL_ADC_Start(&hadc1);

    for(uint8_t i=0;i<ADC_COUNT;i++)
    {
        HAL_ADC_PollForConversion(&hadc1,HAL_MAX_DELAY);

        adcValue[i]=HAL_ADC_GetValue(&hadc1);
    }

    HAL_ADC_Stop(&hadc1);
}

uint16_t ADC_GetRaw(ADC_Channel_t channel)
{
    return adcValue[channel];
}

uint16_t ADC_GetSpeed(void)
{
    return (adcValue[ADC_SPEED]*180)/4095;
}

uint8_t ADC_GetFuel(void)
{
    return (adcValue[ADC_FUEL]*100)/4095;
}

float ADC_GetBatteryVoltage(void)
{
    return (adcValue[ADC_BATTERY]*15.0f)/4095.0f;
}



/*
 * adc_manager.c
 *
 *  Created on: Jul 30, 2026
 *      Author: nazim
 */

#include "adc_manager.h"

extern ADC_HandleTypeDef hadc1;

static uint16_t adcValue[ADC_COUNT] = {0};

/*--------------------------------------------------------------------
 * Read a single ADC channel
 *-------------------------------------------------------------------*/
static uint16_t ADC_ReadChannel(uint32_t channel)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    sConfig.Channel = channel;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;

    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
    {
        return 0;
    }

    HAL_ADC_Start(&hadc1);

    if (HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) != HAL_OK)
    {
        HAL_ADC_Stop(&hadc1);
        return 0;
    }

    uint16_t value = HAL_ADC_GetValue(&hadc1);

    HAL_ADC_Stop(&hadc1);

    return value;
}

/*--------------------------------------------------------------------
 * Update all sensor values
 *-------------------------------------------------------------------*/
void ADC_Manager_Update(void)
{
    adcValue[ADC_SPEED] =
            ADC_ReadChannel(ADC_CHANNEL_0);

    adcValue[ADC_FUEL] =
            ADC_ReadChannel(ADC_CHANNEL_1);

    adcValue[ADC_BATTERY] =
            ADC_ReadChannel(ADC_CHANNEL_2);
}

/*--------------------------------------------------------------------
 * Raw ADC value
 *-------------------------------------------------------------------*/
uint16_t ADC_GetRaw(ADC_Channel_t channel)
{
    if(channel >= ADC_COUNT)
        return 0;

    return adcValue[channel];
}

/*--------------------------------------------------------------------
 * Speed (0-180 km/h)
 *-------------------------------------------------------------------*/
uint16_t ADC_GetSpeed(void)
{
    return (adcValue[ADC_SPEED] * 180U) / 4095U;
}

/*--------------------------------------------------------------------
 * Fuel (0-100%)
 *-------------------------------------------------------------------*/
uint8_t ADC_GetFuel(void)
{
    return (adcValue[ADC_FUEL] * 100U) / 4095U;
}

/*--------------------------------------------------------------------
 * Battery (0-15V)
 *-------------------------------------------------------------------*/
float ADC_GetBatteryVoltage(void)
{
    return (adcValue[ADC_BATTERY] * 15.0f) / 4095.0f;
}

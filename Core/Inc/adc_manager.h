/*
 * adc_manager.h
 *
 *  Created on: Jul 30, 2026
 *      Author: nazim
 */

#ifndef INC_ADC_MANAGER_H_
#define INC_ADC_MANAGER_H_

#include <uart_manager.h>
#include "main.h"

typedef enum
{
    ADC_SPEED = 0,
    ADC_FUEL,
    ADC_BATTERY,

    ADC_COUNT

} ADC_Channel_t;

void ADC_Manager_Update(void);

uint16_t ADC_GetRaw(ADC_Channel_t channel);

uint16_t ADC_GetSpeed(void);

uint8_t ADC_GetFuel(void);

float ADC_GetBatteryVoltage(void);

#endif /* INC_ADC_MANAGER_H_ */

/*
 * vehicle.h
 *
 *  Created on: Jul 30, 2026
 *      Author: nazim
 */

#ifndef INC_VEHICLE_H_
#define INC_VEHICLE_H_

#include "main.h"
#include <stdbool.h>

typedef struct
{
    uint16_t speed;
    uint16_t rpm;
    uint8_t fuel;
    float battery;
    bool ignition;
    bool headlights;
    bool door;

}Vehicle_t;

extern Vehicle_t Vehicle;

void Vehicle_Init(void);
void Vehicle_Update(void);

#endif /* INC_VEHICLE_H_ */

/*
 * ssd1306.h
 *
 *  Created on: Aug 12, 2026
 *      Author: nazim
 */

#ifndef INC_SSD1306_H_
#define INC_SSD1306_H_

#include "main.h"
#include <stdint.h>

#define SSD1306_WIDTH       128
#define SSD1306_HEIGHT      64

#define SSD1306_I2C_ADDR    (0x3C << 1)

#define SSD1306_COLOR_BLACK 0
#define SSD1306_COLOR_WHITE 1

typedef enum
{
    SSD1306_OK = 0,
    SSD1306_ERROR
} SSD1306_Status_t;

void SSD1306_Init(void);

void SSD1306_Fill(uint8_t color);

void SSD1306_GotoXY(uint8_t x, uint8_t y);

void SSD1306_DrawChar(char c);

void SSD1306_Puts(const char *str);

void SSD1306_UpdateScreen(void);


#endif /* INC_SSD1306_H_ */

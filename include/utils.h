#ifndef __UTILS_H
#define __UTILS_H

#include <Arduino.h>
#include <stdarg.h>

void p(const __FlashStringHelper *format, ...);

typedef struct {
  uint8_t TEMP_HUMID = 3;
  uint8_t SCR_CLOCK = 4;
  uint8_t SCR_MOSI = 5;
  uint8_t SCR_DC = 6;
  uint8_t SCR_CS = 7;
} Pins_;

const Pins_ Pins;

#endif

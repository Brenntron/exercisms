#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t band[])
{
  return (uint16_t)band[0] * 10 + (uint16_t)band[1];
}

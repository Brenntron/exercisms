#include "resistor_color.h"

uint16_t color_code(resistor_band_t band)
{
  return (uint16_t)band;
}

resistor_band_t* colors(void)
{
  static resistor_band_t all_colors[] = { BLACK, BROWN, RED, ORANGE, YELLOW,
                                          GREEN, BLUE, VIOLET, GREY, WHITE };
  return all_colors;
}

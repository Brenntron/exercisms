#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t colors[]) {
    resistor_value_t result;
    int value = 0;
    int multiplier = 1;

    if (colors[1] == 0) {
      value = colors[0];
      multiplier = (int)pow(10, colors[2] + 1);
    } else {
      value = colors[0] * 10 + colors[1];
      multiplier = (int)pow(10, colors[2]);
    }

    if (multiplier >= 1000000000) {
        result.value = value;
        result.unit = GIGAOHMS;
    } else if (multiplier >= 1000000) {
        result.value = value * (multiplier / 1000000);
        result.unit = MEGAOHMS;
    } else if (multiplier >= 1000) {
        result.value = value * (multiplier / 1000);
        result.unit = KILOOHMS;
    } else {
        result.value = value * multiplier;
        result.unit = OHMS;
    }

    return result;
}

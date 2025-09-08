#include "space_age.h"


float age(planet_t planet, float seconds)
{
  static const float EARTH_ORBITAL_PERIOD = 31557600.0; // seconds in one Earth year
  //
  if (planet < MERCURY || planet > NEPTUNE) {
     // Invalid planet, return -1.0 to indicate error
     return -1.0;
  }

  return seconds / (EARTH_ORBITAL_PERIOD * PLANET_ORBITAL_PERIODS[planet]);
}

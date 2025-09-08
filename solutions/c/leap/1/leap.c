#include "leap.h"

bool leap_year(int year)
{
    if (year % 4 != 0)
        return 0; // Not a leap year
    if (year % 100 != 0)
        return 1; // Leap year
    if (year % 400 != 0)
        return 0; // Not a leap year
    return 1; // Leap year
}

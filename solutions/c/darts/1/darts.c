#include "darts.h"

/**
 * @brief returns the score for a given landing position
 *
 * @param landing_position { float x, float y }
 * @return uint8_t score
 */
uint8_t score(coordinate_t landing_position)
{
    float x = landing_position.x;
    float y = landing_position.y;
    float distance_squared = x * x + y * y;

    if (distance_squared <= 1.0F)
    {
        return 10; // Inner circle
    }
    else if (distance_squared <= 25.0F)
    {
        return 5; // Middle circle
    }
    else if (distance_squared <= 100.0F)
    {
        return 1; // Outer circle
    }
    else
    {
        return 0; // Missed target
    }
}

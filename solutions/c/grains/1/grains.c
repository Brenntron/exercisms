#include "grains.h"

uint64_t square(uint8_t index)
{
    if (index == 0 || index > 64) {
        return 0;
    }
    return 1ull << (index - 1);
}

uint64_t total(void)
{
  uint64_t total = 0;
  for (unsigned int i = 0; i < 64; i++) {
    total += 1ull << i;
  }
  return total;
}

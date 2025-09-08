#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  unsigned int count = 0;

  while (n > 0) {
    n &= (n - 1); // Clears the least significant set bit.    
    count++;
  }
  return count;
}

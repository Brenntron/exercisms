#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number)
{
  unsigned int sum_of_squares = 0;
  for (unsigned int i = 1; i<= number; i++) {
    sum_of_squares += i * i;
  }
  return sum_of_squares;
}

unsigned int square_of_sum(unsigned int number)
{
  unsigned int square_of_sum = 0;
  for (unsigned int i = 1; i<= number; i++) {
    square_of_sum += i;
  }
  square_of_sum *= square_of_sum;
  return square_of_sum;
}

unsigned int difference_of_squares(unsigned int number)
{
  return square_of_sum(number) - sum_of_squares(number);
}

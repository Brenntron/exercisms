#include "perfect_numbers.h"

kind classify_number(int number)
{
   if (number < 1)
      return ERROR;

   int sum_of_divisors = 0;
   for (int i = 1; i <= number / 2; i++)
   {
      if (number % i == 0)
         sum_of_divisors += i;
   }

   if (sum_of_divisors == number)
      return PERFECT_NUMBER;
   else if (sum_of_divisors > number)
      return ABUNDANT_NUMBER;
   else
      return DEFICIENT_NUMBER;
}

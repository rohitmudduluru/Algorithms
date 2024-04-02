#include <stdio.h>

int add(int x, int y)
{
    while (y != 0)
    {
        int carry = x & y;
        x = x ^ y; 
        y = carry << 1;
    }
    return x;
}

int subtract(int x, int y)
{
  while (y != 0)
    {
      int carry = (~x) & y;
      x = x ^ y;
      y = carry << 1;
    }
  return x;
}

int divide(int x, int y)
{
  int count = 1;
  int y2 = y;
  int quotient = 0;
  while(x>y)
    {
      while (y2 <= x)
        {
          count = add(count, count);
          y2 = y2 << 1;
        }
      quotient = add(quotient, count/2);
      y2 = y2 >> 1;
      x = subtract(x, y2);
      y2 = y;
      count = 1;
    }
  return quotient;
}
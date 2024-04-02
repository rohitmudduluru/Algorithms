#include <stdio.h>

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

int mod(int x, int y)
{
  int y2 = y;
  while(x>y)
    {
      while (y2 <= x)
        {
          y2 = y2 << 1;
        }
      y2 = y2 >> 1;
      x = subtract(x, y2);
      y2 = y;
    }
  return x;
}
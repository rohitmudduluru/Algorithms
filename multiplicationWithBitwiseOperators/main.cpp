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

int multiply(int x, int y)
{
  int y2;
  int r = 0;
  bool a;
  while(y != 0)
    {
      y2 = y & 0b00000001;
      r = add(r, x & (-y2));
      y = y >> 1;
      x = x<<1;
    }
  return r;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long fibonacci_helper(unsigned long long *p, int count)
{
  if (count == 0)
  {
    return *(p-1);
  }
  *(p) = *(p-1) + *(p-2);
  return fibonacci_helper(p+1, count-1);
}
unsigned long long fibonacci(int count)
{
  unsigned long long *p = (unsigned long long*)malloc(100*sizeof(unsigned long long));
  memset(p,0,92);
  *p = 0;
  *(p++) = 1;
  unsigned long long x= fibonacci_helper(p+1, count);
  return x;
}
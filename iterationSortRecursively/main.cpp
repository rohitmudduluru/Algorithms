#include <stdio.h>

int *iteration_sort_recursively_helper(int *n, int count)
{
  if(*n < *(n-1))
  {
  int placeholder;
  placeholder = *(n-1);
  *(n-1) = *n;
  *n = placeholder;
  return iteration_sort_recursively_helper(n-1, count+1);
  }
  else if(count == 1) return 0;
  else return iteration_sort_recursively_helper(n+1, count-1);
}

int *iteration_sort_recursively(int *n, int count)
{

  return iteration_sort_recursively_helper(n+1, count);
}
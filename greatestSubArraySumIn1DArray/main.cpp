#include <stdio.h>
#include <limits.h>

int find_sum(int *list, int n, int *start, int *end)
{
  int sum_so_far = *list;
  int greatest = *list;
  for(int i = 1; i < n-1; i++)
    {
      list++;
      sum_so_far = *list+*(list-1);
      if(sum_so_far > *list) *list = sum_so_far;
      else sum_so_far = *list;
      if(sum_so_far > greatest) 
      {greatest = sum_so_far;
       *start = i-1;
      }
      else *end = i-1;
    }
  return greatest;
}
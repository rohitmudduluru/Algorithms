#include <stdio.h>
#include <limits.h>

int sumrc(int *list, int startrow, int startcol, int endrow, int endcol, int col)
{
  int sum = 0;
  list += startcol;
  list += startrow * col;
  for(int rowcount = 0; rowcount <= endrow - startrow; rowcount++)
    {
    for(int colcount = 0; colcount <= endcol-startcol ;colcount++)
      {
        sum+= *(list+colcount);
      }
      list += col;
    }
  return sum;
}

int find_sum2d(int *list, int row, int col, int *maxstartrow, int *maxstartcol, int *maxendrow, int *maxendcol)
{
  int max = INT_MIN;
  int sum = 0;
  for(int startrow = 0; startrow < row; startrow++){
    for(int endrow = startrow; endrow < row; endrow++){
      for(int startcol = 0; startcol < col; startcol++){
        for(int endcol = startcol; endcol < col; endcol++){
          int sum = sumrc(list, startrow, startcol, endrow, endcol, col);
          if (sum >= max)
            {
              max = sum;
              *maxstartrow = startrow;
              *maxendrow = endrow;
              *maxstartcol = startcol;
              *maxendcol = endcol;
            }
        }
      }
    }
  }
  return max;
}
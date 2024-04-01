//Rohit Mudduluru
//Program to get numbers from command prompt

#include <stdio.h>
int getnum()
{
  int ch;
  int num = 0;
  while(ch != '\n')
    {
      while((ch = getchar())>='0' && ch <= '9')
      {
          ch -= '0';
          num = num * 10 + ch;
      }
    }
  return num;
}

float getnum_with_decimals()
{
  int ch;
  float num = 0;
  int a = 0;
  while(ch != '\n')
    {
      while((ch = getchar())>='0' && ch <= '9')
      {
        if (a == 0)
        {
          ch -= '0';
          num = num * 10 + ch;
        }
        if (a == 1)
        {
          ch -= '0';
          num = num * 10 + ch;
          num /= 10;
        }
      }
      if (ch == '.') a = 1;
    }
  return num;
}
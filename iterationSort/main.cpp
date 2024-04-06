#include <stdio.h>

float getnum()
{
  int ch;
  float num = 0;
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

void iteration_sort()
{
  printf("Enter the size of the list you would like: ");
  int size = getnum();
  int a[size];
  for(int i = 0; i < size; i++)
    {
      a[i] = rand()%100;
    }
  for(int i = 1; i < size; i++)
    {
      if (a[i]<a[i-1])
      {
        for(int x = i; x > 0 && a[x] < a[x-1]; x--)
          {
            int placeholder;
            placeholder = a[x-1];
            a[x-1] = a[x];
            a[x] = placeholder;
          }
      }
    }
  for(int i = 0; i < size; i++)
    {
      printf("%d ", a[i]);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dec2hex_helper(int num, char *s2, int count)
{
  if (count == 0)
  {
    return s2+2;
  }
  if (num%16>=10) *s2 = num% 16 + 'A' - 10;
  else *s2 = num%16 + '0';
  num = num/16;
  s2--;
  if (num%16>=10) *s2 = num%16 + 'A' - 10;
  else *s2 = num%16 + '0';
  s2--;
  *s2 = ' ';
  return dec2hex_helper(num/16, s2-1, count - 1);
}

void dec2hex()
{
  printf("Input a number: ");
  int num = 0;
  int ch;
  while((ch = getchar()) >= '0' && ch <= '9')
    {
      num = num*10 + (ch - '0');
    }
  int count = sizeof(num);
  char *s = (char*)malloc(count * 3+2);
  memset(s, 0, count * 3);
  s = dec2hex_helper(num, s + strlen(s) - 1, count);
  printf("%s\n", s);
}
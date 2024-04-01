//
//  main.c
//  base10ToHexadecimal
//
//  Rohit Mudduluru
//  A code to convert base 10 numbers to base 16

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Give a base ten number: \n");
    int n = 0, b = 0, d = 0, e[100];
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (ch >= '0' && ch <= '9')
        {
            n = n * 10;
            n = (ch - '0') + n;
        }
    }
    while(n>=16)
      {
        e[d] = n%16;
        n = n - n%16;
        d++;
        n= n/16;
      }
      e[d] = n;
      printf("\nHexadecimal: ");
      while (d >= 0)
      {
        if(e[d]==10)
        {
          printf("A");
        }
        else if(e[d]==11)
        {
          printf("B");
        }
        else if(e[d]==12)
        {
          printf("C");
        }
        else if(e[d]==13)
        {
          printf("D");
        }
        else if(e[d]==14)
        {
          printf("E");
        }
        else if(e[d]==15)
        {
          printf("F");
        }
        else if(e[d]<=9)
        {
          printf("%d", e[d]);
        }
        d--;
      }
    printf("\n");
}

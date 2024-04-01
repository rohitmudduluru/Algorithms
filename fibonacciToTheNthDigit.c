//Rohit Mudduluru
//A code which prints out fibonacci numbers to the nth digit

#include <stdio.h>

int main(void) {
  printf("How many numbers of fibonacci do you want to print?\n");
  int n;
  scanf("%d", &n);
  if(n == 1)
    printf("0");
  if(n >= 2)
    printf("0 1 ");
  for(long a = 0, b = 1, c = 0, i = 2; i < n; i++)
    {
      c = a + b;
      a = b;
      b = c;
      printf("%d ", c);
    }
}
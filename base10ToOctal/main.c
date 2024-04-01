//  main.c
//  base10ToOctal
//
//  Rohit Mudduluru
//  A code to convert base 10 numbers to base 8

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Give a base ten number: \n");
    int n = 0, b = 0, convert[100];
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (ch >= '0' && ch <= '9')
        {
            n = n * 10;
            n = (ch - '0') + n;
        }
    }
    
    
    while(n>=8)
    {
        convert[b]=n%8;
        n = n - n%8;
        b++;
        n /= 8;
    }
    convert[b]= n;
    printf("octal: ");
    while(b >= 0)
    {
        printf("%d", convert[b]);
        b = b - 1;
    }
    printf("\n");
}

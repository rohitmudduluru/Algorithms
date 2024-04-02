#include <stdio.h>
#include <string.h>

bool the_actual_ispalindrome(char *s2, char *s3)
{
  if(s2 >= s3) return true;
  else if(*s2 != *s3) return false;
  return(the_actual_ispalindrome(s2+1, s3-1));
}

bool ispalindrome(char *s)
{
  return the_actual_ispalindrome(s, (s + strlen(s) - 1));
}
//#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int getFsize(const char *name)
{
  FILE* fp;
  
  fp = fopen(name, "r");
  if (!fp)
  {
    printf("Failed to open file");
    //exit(EXIT_FALUIRE);
  }

  fseek(fp, 0L, SEEK_END);
  long long int size = ftell(fp);
  fclose(fp);
  return size;
}

char *moomoo(const char* name)
{
  FILE* fp;
  fp = fopen(name, "r");
  //int wsize = (strlen(word));
  long long int size = (getFsize(name) + 1);
  char *s = (char *)malloc(size);
  char *word = (char *)malloc(size);
  memset(s, 0, size);
  memset(word, 0, size);
  fgets(s, size, fp);
  fscanf(fp, "%s", word);
  fclose(fp);
  long long int wsize = (strlen(word));
  char *news = (char *)malloc(size);
  memset(news, 0, size);
  char *p = news;
  char *s2 = s;
  while (*s2 != 0 || *s2 == ' ') {
    *p++ = *s2++;
    if(p - news >= wsize)
    {
      if (memcmp(p - wsize, word, wsize) == 0) {
        p = p - wsize;
        // if (*s2 == ' ') {
        //   p = p - 1;
        // }
      }
    }
  }
  memset(p, 0, ((news + size) - p));
  return news;
}

int main() {
  const char *h = "censor.in";
  const char *i = "censor.out";
  FILE* fp;
  fp = fopen(i, "w");
  char *s;
  s = moomoo(h);
  if(s != NULL)
  {
  fwrite(s, sizeof(char) ,strlen(s), fp);
  printf("New string:\n%s", s);
  }
  fclose(fp);
  
}
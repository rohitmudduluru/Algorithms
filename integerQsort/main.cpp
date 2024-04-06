#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char ubyte;
int compare(const void *p, const void *q)
{
  if (*(int*)p == *(int*)q) 
    return 0;
  if (*(int*)p > *(int*)q)
    return 1;
  if (*(int*)p < *(int*)q)
    return -1;
}

void swap(int *a, int *b)
{
  int temp;
  temp = *b;
  *b = *a;
  *a = temp;
}

void Qsort_helper(int* low, int* high, int* pivot, size_t elements, int* start, int* end)
{
  for(int i = 1;low < pivot || high > pivot;i++)
    {
      if (compare(low, pivot) <= 0 && low < pivot)
        low++;
      else if(low < pivot){
        swap(low, pivot);
        pivot = low;
        //low = list + i;
        low++;
      }
      else {}
      if(compare(high, pivot) >= 0 && high > pivot)
        high--;
      else if(high > pivot){
        swap(high, pivot);
        pivot = high;
        //high = list + (elements*2) - i - 1;
        high--;
      }
      else  {}
    }
  if (start >= end) 
    return;
   Qsort_helper(start, pivot - 1, pivot - (pivot - start+1)/2, elements/2, start, pivot - 1);
  
   Qsort_helper(pivot+1, end,pivot + (end - pivot+1)/2, elements/2, pivot + 1, end);
}

void Qsort(int* list, size_t elements, int(*compare)(const void *, const void *))
{
  int* low = list;
  int* high = list + elements - 1;
  int* pivot = list + int(elements/2);
  Qsort_helper(low, high, pivot, (elements/2), list, high);
}

int main() {
  time_t t;
  srand((unsigned) time(&t));
  int big = 100000;
  int num[big];
  for(int i = 0; i < big; i++)
  {
    num[i] = i;
  }
  for(int i = 0; i < big; i++)
    {
      swap(&num[i], &num[(rand()%big)]);
    }
  Qsort(&num[0], sizeof(num)/sizeof(num[0]), compare);
  for(int i = 0; i < big; i++)
    {
      printf("%d ", num[i]);
    }
}
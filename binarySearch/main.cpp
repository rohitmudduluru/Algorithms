#include <stdio.h>

int *binarySearch(int target, int *list, int elements)
{
  if (elements%2 == 0 || elements == 1)
  elements = elements/2;
  else if (elements%2 == 1 && elements != 1)
  elements = elements/2 + 1;
  if (*list == target)
    return list;
  else if (elements == 0) return NULL;
  if (target >= *(list + elements))
    return binarySearch(target, list + elements, elements);
  else 
    return binarySearch(target, list, elements);
}
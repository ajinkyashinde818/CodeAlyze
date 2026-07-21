#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int string_compar(const void *a, const void *b)
{
    return(strcmp(*(char**)a, *(char**)b));
}

int main()
{
  int n = 0;
  int r = 0;
  int nr = 0;

  scanf("%d %d", &n,&r);

  if (n >= 10)
  {
    printf("%d", r);
  }
  else
  {
    nr = r + 100 * (10 - n);
    printf("%d", nr);
  }
  //qsort((void*)ary, n, sizeof(char*), string_compar);

    return 0;
}

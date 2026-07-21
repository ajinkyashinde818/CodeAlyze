#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i,n,minv,maxv;
  int *array;

  scanf("%d",&n);

  array = (int *)malloc(sizeof(int) * n);
  if(array == NULL) exit(0);

  for(i = 0;i < n;i++){
    scanf("%d",&array[i]);
  }

  maxv = array[1] - array[0];
  minv = array[0];
  for(i = 1;i < n;i++){
    if(maxv < (array[i] - minv)) maxv = array[i] - minv;
    if(minv > array[i]) minv = array[i];
  }

  printf("%d\n",maxv);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void){
  int *a;
  int n, i, j;
  int max = -1000000000;
  scanf("%d", &n);
  a = malloc(n * sizeof(int));
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  int minv = a[0];
  for(i = 1; i < n; i++){
    if(max < a[i] - minv) max = a[i] - minv;
    if(minv > a[i]) minv = a[i];
  }


  printf("%d\n", max);
  return 0;
}

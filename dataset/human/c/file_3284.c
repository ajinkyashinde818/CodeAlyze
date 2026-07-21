#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
  int k, n, i, max;
  int r;
  scanf("%d %d", &k, &n);
  int a[n];

  for(i=0; i<n; i++)scanf("%d", &a[i]);

  max = 0;
  for(i=0; i<n-1; i++){
    if(max < a[i+1]-a[i])max = a[i+1] - a[i];
  }

  r = a[0] + k - a[n-1];
  if(max < r)max = r;

  //printf("%d %d %d\n", k, n, max);
  //for(i=0; i<n; i++)printf("%d ", a[i]);
  //printf("\n");
  printf("%d\n", k-max);
  return 0;
}

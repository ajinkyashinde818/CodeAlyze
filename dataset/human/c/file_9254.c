#include<stdio.h>
#include<stdlib.h>
int main(void){
  int n, k, i, count = 0;
  int *h;
  scanf("%d %d", &n, &k);
  h = (int *)malloc(n * sizeof(int));
  
  for (i = 0; i < n; i++) {
    scanf("%d", h + i);
  }
  for (i = 0; i < n; i++){
    if (k <= h[i])count++;
  }
  printf("%d", count);
  return (0);
}

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
  int max, min;
  int n, i, j;
  int *a = NULL;

  scanf("%d", &n);
  a = (int*)malloc(sizeof(int) * n);

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  max = INT_MIN;
  min = a[0];
  for(i = 1; i < n; i++){
    if(max < a[i] - min){
      max = a[i] - min;
    }
    if(min > a[i]){
      min = a[i];
    }
  }

  printf("%d\n", max);

  return 0;
}

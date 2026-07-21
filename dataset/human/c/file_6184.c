#include<stdio.h>

int main(){
  int n, i, max, min;
  scanf("%d", &n);
  int A[n];
  for(i = 0 ; i < n ; i++){
    scanf("%d", &A[i]);
  }
  max = A[1] - A[0];
  min = A[0];
  for(i = 1 ; i < n ; i++){
    if(min > A[i - 1]) min = A[i - 1];
    if(max < A[i] - min) max = A[i] - min;
  }
  printf("%d\n", max);
}

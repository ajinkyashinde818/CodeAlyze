#include<stdio.h>
#define N 200000

int main(){
  int i, j, n, max, min, sum;
  int A[N];
  
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  max = A[1] - A[0];
  min = A[0];
  for(i = 1; i < n; i++){
    if(max < A[i] - min) max = A[i] - min;
    if(min > A[i]) min = A[i];
  }
  printf("%d\n",max);
  return 0;
}

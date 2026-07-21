#include <stdio.h>
#define MAX 200000
int main(){
  int i,j,n,min = 100000000,time,max,A[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  min = A[0];
  max = A[1] - A[0];
  for(i=1;i<n;i++){
    if(max < A[i] -min)
      max = A[i] -min;
    if(min > A[i])
      min = A[i];
  }
  printf("%d\n",max);
  return 0;
}

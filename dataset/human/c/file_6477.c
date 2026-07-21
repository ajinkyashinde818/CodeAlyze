#include <stdio.h>

int hikaku(int *,int);

int main(){
  int i,n,min,max = -2000000000;;
  int A[200000];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  min = A[0];

  for(i = 1; i < n; i++){
    if(max < A[i]-min) max = A[i]-min;
    if(min > A[i]) min = A[i];
  }
  printf("%d\n",max);

  return 0;

}

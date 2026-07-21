#include <stdio.h>
#include <math.h>

int main(){
  int i,j,n,A[200000];
  int t;

  t = 1 - pow(10,9);

  scanf("%d",&n);

  for(i=0; i < n; i++){
    scanf("%d",&A[i]);
  }

  for(i=n-1; i >= 0; i--){
    if(t > A[i]){
      continue;
    }
    for(j=i-1; j >= 0; j--){
      if(t < A[i] - A[j]){
	t = A[i] - A[j];
      }
    }
  }

  printf("%d\n",t);

  return 0;
}

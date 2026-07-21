#include <stdio.h>
#define N 200000

int main(){

  int A[N],n;
  int min=0,max=0,j,i;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  min=A[0];
  max=A[1]-A[0];
  for(j=1;j<=n-1;j++){
    if(max<A[j]-min)max=A[j]-min;
    if(min>A[j])min=A[j];
  }

  printf("%d\n",max);
  
  return 0;
}

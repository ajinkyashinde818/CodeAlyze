#include <stdio.h>
int main(){
  int i,n,A[200000],min,max=-1000000000,a;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  min=A[0];
  for(i=1;i<n;i++){
    a=A[i]-min;
    if(a>max)max=a;
    if(A[i]<min)min=A[i];
  }
  printf("%d\n",max);
  return 0;
}

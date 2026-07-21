#include <stdio.h>

int main(){
  int k,n;
  scanf("%d %d",&k,&n);
  int A[n+1],i,j,a;
  for(i=0;i<n;i++){
    scanf("%d",&j);
    A[i]=j;
  }
  A[n]=A[0]+k;
  a=0;
  for(i=0;i<n;i++){
    if(A[i+1]-A[i]>a){
      a=A[i+1]-A[i];
    }
  }
  i=k-a;
  printf("%d\n",i);
  return 0;
}

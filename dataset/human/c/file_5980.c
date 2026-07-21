#include<stdio.h>

#define MAX 200000

int main(){
  int A[MAX],n,i,M,m;
  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  M=A[1]-A[0];
  m=A[0];
  for(i=1;i<n;i++){
    if(M<A[i]-m)M=A[i]-m;
    if(m>A[i])m=A[i];
  }
  printf("%d\n",M);
  return 0;
}

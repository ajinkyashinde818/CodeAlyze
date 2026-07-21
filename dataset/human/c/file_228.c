#include <stdio.h>
#include <stdlib.h>
int main(){
  int N,i,k=0,m=1<<31-1;
  long ans=0;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
    if(A[i]<0)k++;
  }
  for(i=0;i<N;i++){
    if(k%2==1)if(m>abs(A[i]))m=abs(A[i]);
    ans+=abs(A[i]);
  }
  if(k%2==1)ans-=m*2;
  printf("%ld\n",ans);
  return 0;
}

#include<stdio.h>
#include<math.h>

int main(){
  int i,j,k,N;
  long ans=0,tmp=0,tmpp=0,min=10000000000;
  
  scanf("%d",&N);
  long A[N];
  for(i=0;i<N;i++){
    scanf("%ld ",&A[i]);
    tmp+=A[i];
  }
  for(i=0;i<N-1;i++){
    tmpp+=A[i];
    if(labs(tmp-2*tmpp)<min)
      min=labs(tmp-2*tmpp);
  }
  printf("%ld\n",min);
  return 0;
}

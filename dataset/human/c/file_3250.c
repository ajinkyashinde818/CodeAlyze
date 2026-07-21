#include<stdio.h>
#include<math.h>

int main(){
  long long i,j,k,l,N,K,max=0,ans=0;
  
  scanf("%lld %lld",&K,&N);
  
  long long A[N],B[N];
  
  for(i=0;i<N;i++){
    scanf("%lld ",&A[i]);
    if(i != 0){
      B[i-1]=A[i]-A[i-1];
      if(max < B[i-1])
        max = B[i-1];
      ans+=B[i-1];
    }
  }
  B[N-1]=abs(K-A[N-1])+A[0];
  if(max < B[N-1])
    max = B[N-1];
  ans+=B[N-1];
  
  printf("%lld\n",ans-max);
  return 0;
}

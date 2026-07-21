#include<stdio.h>

typedef long long ll;

int main(void){
  ll N;
  ll A[100001];
  ll i;
  ll S=0,Nsum,subsum=0,k,tmp;
  scanf("%lld",&N);
  for(i=0;i<N;i++){
    scanf("%lld",&A[i]);
    S+=(ll)A[i];
  }
  Nsum=(ll)N*(ll)(N+1)/2;
  if(S%Nsum){
    puts("NO");
    return 0;
  }
  k=S/Nsum;
  for(i=0;i<N;i++){
    tmp=A[i%N]+k-A[(i+1)%N];
    if(tmp%N || tmp<0){
      puts("NO");
      return 0;
    }
    subsum+=(ll)tmp/N;
  }
  puts(subsum==k?"YES":"NO");
  return 0;
}

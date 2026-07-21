#include<stdio.h>
#include<stdlib.h>
int min(int a,int b){return a>b?b:a;}

int main(void){
  long long int mod = 1e9+7;
  int N,M;
  int a,i,j;
  scanf("%d %d",&N,&M);
  
  int v[N+1];
  for(i=0;i<N+1;i++) v[i] = 1;
  for(i=0;i<M;i++){
    scanf("%d",&a);
    v[a] = 0;
  }
  
  long long int dp[N+1];
  for(i=0;i<N+1;i++) dp[i] = 0;
  dp[0] = 1;
  for(i=0;i<N;i++){
    for(j=i+1;j<=min(N,i+2);j++){
      if(v[j]) dp[j] = (dp[j]+dp[i]) % mod;
    }
  }
  
  printf("%lld\n",dp[N]);
  return 0;
}

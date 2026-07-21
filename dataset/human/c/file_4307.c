#include <stdio.h>
#define mod 1000000007

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  int a;
  int flag[N+1];
  for (int i = 0; i < N+1; i++) {
    flag[i] = 0;
  }
  for (int i = 0; i < M; i++) {
    scanf("%d",&a);
    flag[a] = 1;
  }

  long long dp[N+1];
  for (int i = 0; i < N+1; i++) {
    dp[i] = 0;
  }
  dp[0] = 1;

  for (int i = 0; i <= N; i++) {
    if(i < N && flag[i+1] == 0) dp[i+1] += dp[i] , dp[i+1] %= mod;
    if(i < N-1 && flag[i+2] == 0) dp[i+2] += dp[i] , dp[i+2] %= mod;
  }

  /* printf("\n"); */
  /* for (int i = 0; i < N+1; i++) { */
  /*   printf("%lld\n",dp[i]); */
  /* } */

  printf("%lld\n",dp[N]);

  return 0;
}

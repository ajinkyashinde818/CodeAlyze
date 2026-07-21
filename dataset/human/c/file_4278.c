#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef long long ll;

#define INF 100100100100
#define MODSIZE 1000000007


int main(){
  long long dp[100007];
  long long a[100007];
  int flag[100007];
  int i,j,k,n,m;

  scanf("%d %d", &n, &m);
  for(i = 0;i <= n;i++){
    dp[i] = 0;
    flag[i] = 0;
  }

  for(i = 0;i < m;i++){
    scanf("%lld", &a[i]);
    flag[a[i]] = 1;
  }

  dp[0] = 1;
  dp[1] = 1;

  for(i = 2;i <= n;i++){
    if(flag[i - 1] == 0) dp[i] = (dp[i - 1] + dp[i]) % MODSIZE;
    if(flag[i - 2] == 0) dp[i] = (dp[i - 2] + dp[i]) % MODSIZE;
  }

  printf("%lld\n", dp[n] % MODSIZE);
  return 0;
}

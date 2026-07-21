#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
int main(void) {
   int n;
   scanf("%d", &n);
   int *L = (int *)malloc((n+1) * sizeof(int));
   ll **dp = (ll **)malloc((n+2) * sizeof(ll *));
   for (int i = 0; i < n+2; i++) {
      dp[i] = (ll *)malloc(sizeof(ll) * 2);
   }
   for (int i = 0; i < n; i++) {
      scanf("%d", &L[i]);
   }
   L[n+1] = 0; 
   dp[0][0] = L[0];
   dp[0][1] = -L[0];
   for (int i = 0; i < n; i++) {
      dp[i+1][0] = MAX(dp[i][0]+L[i+1],dp[i][1]-L[i+1]);
      dp[i+1][1] = MAX(dp[i][0]-L[i+1],dp[i][1]+L[i+1]);
   }
   printf("%lld\n",dp[n-1][0]);
}

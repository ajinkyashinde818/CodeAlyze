#include<stdio.h>
#define MOD 1000000007
long int DP[100001];

long int dp(long int n);

int main(void){
 	int N,M,x;
    scanf("%d",&N);
    scanf("%d",&M);
    for(int i=0;i<100001;i++){
    	DP[i] = -1; 
    }
    for(int i=0;i<M;i++){
      scanf("%d",&x);
      DP[x] = 0;
    } 
    DP[0] =1;
  printf("%ld",dp(N));
}

long int dp(long int n){
 if(DP[n] >= 0 ) return DP[n];
 if(n > 1); return DP[n] = (dp(n-1) + dp(n-2))%MOD;
 if(n == 1) return 1;
};

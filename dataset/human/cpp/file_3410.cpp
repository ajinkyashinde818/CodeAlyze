#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;


int n;
long long a[100002];
long long dp[100002][2];
long long rec(int pos, int stat){
	if (pos == 0){return 0ll;}
	dp[pos][stat] = max(rec(pos-1, 0) + (2*stat-1)*(-1)*a[pos-1], rec(pos-1, 1) - (2*stat-1) * (-1) * a[pos-1]);
	return dp[pos][stat];
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	dp[1][0] = a[0];
	dp[1][1] = -a[0];
	for(int j=2;j<=n;j++){
		dp[j][0] = max(dp[j-1][0] + a[j-1], dp[j-1][1] - a[j-1]);
		dp[j][1] = max(dp[j-1][0] - a[j-1], dp[j-1][1] + a[j-1]);
	}
	printf("%lld\n", dp[n][0]);	
	return 0;
}

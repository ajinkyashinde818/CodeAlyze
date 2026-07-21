#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
ll dp[100001][2];//dp[i+1][j]...i番目で反転させたときのi+1番目までの最大値
ll a[100000];
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	fill(dp[0],dp[100001],0);
	
	dp[0][0]=0;
	dp[0][1]=-1e14+1;
	for(int i=0;i<n;i++)
	{
		//i+1番目ではひっくり返さない
		dp[i+1][0]=max(dp[i][1]-a[i],dp[i][0]+a[i]);
		//i+1番目でひっくり返す
		dp[i+1][1]=max(dp[i][0]-a[i],dp[i][1]+a[i]);
	}
	ans=dp[n][0];//n番目はひっくり返せない
	cout<<ans<<endl;
	return 0;
}

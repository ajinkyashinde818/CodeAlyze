#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100005],dp[2][100005];
int main(){
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	dp[0][0]=a[0],dp[1][0]=-a[0];
	for(int i=1;i<n;i++){
		dp[0][i]=max(dp[0][i-1]+a[i],dp[1][i-1]-a[i]);
		if(i!=n-1)dp[1][i]=max(dp[0][i-1]-a[i],dp[1][i-1]+a[i]);
	}
	cout << max(dp[0][n-1],dp[1][n-1]);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
long long ans,dp[2*N];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long a;
		cin>>a;
		dp[i+1]=dp[i]+a;
	}
	ans=1e18;
	for(int i=1;i<n;i++)
		ans=min(ans,abs((dp[n]-dp[i])-dp[i]));
	cout<<ans<<endl;
	return 0;
}

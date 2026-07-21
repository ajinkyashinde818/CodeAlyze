#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;


int main(void)
{
	int r, g, b, n;

	while(scanf("%d%d%d%d", &r, &g, &b, &n)==4)
	{
		vll dp(n+1);

		dp[0]=1;
		for(int i=0;i+r<=n;i++)
		{
			dp[i+r]+=dp[i];
		}
		for(int i=0;i+g<=n;i++)
		{
			dp[i+g]+=dp[i];
		}
		for(int i=0;i+b<=n;i++)
		{
			dp[i+b]+=dp[i];
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}

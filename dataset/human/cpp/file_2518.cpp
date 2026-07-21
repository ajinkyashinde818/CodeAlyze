#include<cstdio>
#include<algorithm>
using std::max;

typedef long long ll;
const int maxn = 1e5 + 10;
const ll INF = 1ll<<60;

ll dp[maxn][2];//1: flipped

ll A[maxn];

inline void upt(ll &x, ll y)
{
	x = x < y ? y : x;
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%lld", &A[i]);
		dp[i][0] = dp[i][1] = -INF;
	}
	
	A[0] = 0;
	dp[1][0] = A[1];
	for(int i = 2; i <= N; ++i)
	{
		upt(dp[i][0], dp[i-1][0] + A[i]);
		upt(dp[i][0], dp[i-1][1] + A[i]);
		upt(dp[i][1], dp[i-1][0] - A[i] - 2 * A[i - 1]);
		upt(dp[i][1], dp[i-1][1] - A[i] + 2 * A[i - 1]);
	}
	printf("%lld\n", max(dp[N][0], dp[N][1]));
}

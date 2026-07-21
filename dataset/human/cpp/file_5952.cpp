#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100000;
ll x[MAXN + 5], v[MAXN + 5];
ll dp1[MAXN + 5], dp2[MAXN + 5];
int main() {
	int N; ll C;
	scanf("%d%lld", &N, &C);
	for(int i=1;i<=N;i++) {
		scanf("%lld%lld", &x[i], &v[i]);
		dp1[i] = dp1[i-1] - (x[i] - x[i-1]) + v[i];
	}
	for(int i=N;i>=1;i--) {
		x[i] = C - x[i];
		dp2[i] = dp2[i+1] - (x[i] - x[i+1]) + v[i];
	}
	ll Max1 = 0, Max2 = 0, ans = 0;
	x[0] = C;
	for(int i=N;i>=0;i--) {
		ans = max(ans, max(dp1[i] + Max1, dp1[i] + Max2 - (C - x[i])));
		Max1 = max(Max1, dp2[i] - x[i]);
		Max2 = max(Max2, dp2[i]);
	}
	printf("%lld\n", ans);
}

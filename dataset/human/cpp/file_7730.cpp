#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int SIZE = 200002;
int N;
lli num[SIZE];
lli pSum[SIZE];

lli absol(lli x) {
	return x < 0 ? -x : x;
}

int main()
{
	lli ans = 10000000000000000L;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &num[i]);
		pSum[i] = pSum[i - 1] + num[i];
	}
	for (int i = 1; i < N; i++) {
		lli cand = absol(2 * pSum[i] - pSum[N]);
		if (cand < ans)
			ans = cand;
	}
	printf("%lld\n", ans);
}

#include <cstdio>
#include <iostream>
using namespace std;

long long x[100000];
long long v[100000];
long long cw[100000];
long long ccw[100000];

int main() {
	long long N, C;
	scanf("%lld %lld", &N, &C);
	for (int i=0; i<N; i++) {
		scanf("%lld %lld", x+i, v+i);
	}

	long long ans = 0;

	long long sum = 0;
	for (int i=0; i<N; i++) {
		sum += v[i];
		cw[i] = max(i ? cw[i-1] : 0ll, sum - x[i]);
	}

	ans = cw[N-1];

	long long rsum = 0;
	for (int i=N-1; i>=0; i--) {
		rsum += v[i];
		ans = max(ans, (i ? cw[i-1] : 0) + rsum - (C-x[i])*2ll);
	}

	long long sum2 = 0;
	for (int i=N-1; i>=0; i--) {
		sum2 += v[i];
		ccw[i] = max(i==N-1 ? 0ll : ccw[i+1], sum2 - (C - x[i]));
	}

	ans = max(ans, ccw[0]);

	long long rsum2 = 0;
	for (int i=0; i<N; i++) {
		rsum2 += v[i];
		ans = max(ans, (i==N-1 ? 0ll : ccw[i+1] + rsum2 - x[i]*2ll));
	}

	cout << ans << endl;
	return 0;
}

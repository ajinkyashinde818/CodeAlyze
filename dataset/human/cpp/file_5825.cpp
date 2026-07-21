#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int iinf = 1 << 29;
const int imax = ~(1 << 31);
const long long linf = 1ll << 61;
const long long lmax = ~(1ll << 63);

#define dump(x) cerr << #x << " : " << x << '\n'
#define MOD(x, y) (((y) + (x) % (y)) % (y))

ll N, C;
ll x[100000];
ll v[100000];

ll for1[100001];
ll for2[100001];
ll rev1[100001];
ll rev2[100001];

int main(int argc, char* argv[])
{
	scanf("%lld%lld", &N, &C);
	for (int i = 0; i < N; i++) {
		scanf("%lld%lld", &x[i], &v[i]);
	}
	ll M1 = 0;
	ll M2 = 0;
	ll sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += v[i - 1];
		M1 = max(M1, sum - x[i - 1]);
		M2 = max(M2, sum - 2 * x[i - 1]);
		for1[i] = M1;
		for2[i] = M2;
	}
	M1 = 0; M2 = 0;
	sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		sum += v[i];
		M1 = max(M1, sum - (C - x[i]));
		M2 = max(M2, sum - 2 * (C - x[i]));
		rev1[i] = M1;
		rev2[i] = M2;
	}
	ll ans = 0;
	for (int i = 0; i <= N; i++) {
		ans = max(ans, max(for2[i] + rev1[i], for1[i] + rev2[i]));
	}

	printf("%lld\n", ans);

	return 0;
}

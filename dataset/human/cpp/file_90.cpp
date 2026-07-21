#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007; //998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void D();

int main()
{
	D();
	fflush(stdout);
	return 0;
}

static void D()
{
	int R, G, B, N;
	get(R, G, B);
	get(N);

	LLONG ans = 0;
	for (int r = 0; r * R <= N; r++) {
		for (int g = 0; ((g * G + r * R) <= N); g++) {
			int bcnt = N - (r * R) - (g * G);
			int b = bcnt / B;
			if ((bcnt % B == 0) && (b >= 0)) {
				ans++;
			}
		}
	}
	printf("%lld\n", ans);
}

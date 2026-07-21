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
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
}

static void exec();

int main()
{
	exec();
	fflush(stdout);
	return 0;
}


static void exec()
{
	int N, M;
	get(N, M);

	std::vector<std::string> ai(N), bi(M);
	for (int i = 0; i < N; i++) {
		get(ai[i]);
	}
	for (int i = 0; i < M; i++) {
		get(bi[i]);
	}

	for (int h = 0; h < N; h++) {
		if (h + M > N) break;
		for (int w = 0; w < N; w++) {
			if (w + M > N) break;

			bool match = true;
			for (int i = 0; (i < M) && match; i++) {
				for (int j = 0; (j < M) && match; j++) {
					if (bi[i][j] != ai[h + i][w + j]) {
						match = false;
					}
				}
			}
			if (match) {
				printf("Yes\n");
				return;
			}
		}
	}
	printf("No\n");
}

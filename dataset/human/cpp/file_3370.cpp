#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

const int MAXN = 1e5+1;
const int MOD = 1e9 + 7;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define FAILNO {printf("NO\n"); return 0;}
#define FAIL1 {printf("-1\n"); return 0;}

int N;
int A[MAXN];

int main() {
#ifdef OJ
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif

	scanf("%d", &N);
	int zero = 0, neg = 0;
	int mnabs = 1e9+1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);

		if (A[i] == 0) zero++;
		else {
			if (A[i] < 0) neg++;
			mnabs = min(mnabs, abs(A[i]));
		}
	}

	LL ans = 0;
	if (zero) {
		for (int i = 0; i < N; i++) 
			ans += abs(A[i]);
	} else if (neg % 2 == 0) {
		for (int i = 0; i < N; i++) 
			ans += abs(A[i]);
	} else {
		int f = 0;
		for (int i = 0; i < N; i++) {
			if (abs(A[i]) == mnabs) {
				if (!f) ans -= abs(A[i]);
				else ans += abs(A[i]);
				f = 1;
			} else {
				ans += abs(A[i]);
			}
		}
	}

	printf("%lld\n", ans);
	return 0;
}

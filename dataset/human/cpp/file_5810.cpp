#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <locale>
using namespace std;
#define MS0(I) memset(I, 0, sizeof(I));
#define MS1(I) memset(I, -1, sizeof(I));
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, s, n) for(int i = (s); i < (n); ++i)
#define per1(i, a, b) for(int i = a; i >= b; --i)
#define DRI(A) int A; scanf("%d", &A);
#define DRII(A, B) int A, B; scanf("%d %d", &A, &B);
#define DRIII(A, B, C) int A, B, C; scanf("%d %d %d", &A, &B, &C);
#define MP make_pair 
#define pb push_back
#define F first
#define S second
#define ALL(I) (I).begin(), (I).end()
typedef const void CV;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = (int)1e9;
const int mod = (int)1e9+7;
const int MAX = (int)1e5+5;
pair<LL, LL> store[MAX];
LL dpl[MAX];
LL dpr[MAX];
int main(void){
	int n; LL c; scanf("%d %lld", &n, &c);
	rep1(i, 1, n+1) scanf("%lld %lld", &store[i].F, &store[i].S);
	LL cur = 0, x = 0;
	rep1(i, 1, n+1){
		cur += x - store[i].F + store[i].S;
		dpl[i] = max(dpl[i-1], cur);
		x = store[i].F;
	}
	cur = 0; x = c;
	per1(i, n, 1){
		cur += store[i].F - x + store[i].S;
		dpr[i] = max(dpr[i+1], cur);
		x = store[i].F;
	}
	LL ans = 0;
	rep1(i, 1, n+1) ans = max(ans, dpl[i]);
	rep1(i, 1, n+1) ans = max(ans, dpr[i]);
	per1(i, n, 1) ans = max(ans, dpr[i] + dpl[i-1] - (c - store[i].F));
	rep1(i, 1, n+1) ans = max(ans, dpl[i] + dpr[i+1] - store[i].F);
	printf("%lld\n", ans);
	return 0;
}

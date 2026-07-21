#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* define */
#define Yes(X) puts ( (X) ? "Yes" : "No")
#define YES(X) puts ( (X) ? "YES" : "NO")
#define FOR(i, a, b) for ( int i = (a); i < (b) ; i++)
#define REP(i, n) for ( int i = 0; i < (n) ; i++)
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max3(a, b, c) ((max((a), (b)) > (c)) ? max((a), (b)) : (c))
#define min3(a, b, c) ((min((a), (b)) < (c)) ? min((a), (b)) : (c))

/* const */
const int MOD = 1000000007;

/* alias */
typedef long long ll;
typedef unsigned  u;

/* function */
int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}
int cmp2(const void *a, const void *b) {
	return *(int*)b - *(int*)a;
}
int gcd(int a, int b) {
	if (b != 0)return gcd(b, a % b);
	return a;
}
ll Lgcd(ll a, ll b) {
	if (b != 0) return Lgcd(b, a % b);
	return a;
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
ll Llcm(ll a, ll b) {
	return a / Lgcd(a, b) * b;
}

/* main */

int main() {
	int h, w, f = 1, a[] = { -1,0,1,0 }, b[] = { 0,1,0,-1 };
	char s[50][51];
	scanf("%d%d", &h, &w);
	REP(i, h)scanf("%s", &s[i]);
	REP(i, h)REP(j, w) {
		if (s[i][j] == '.') continue;
		int c = 0;
		REP(k, 4) if (s[i + a[k]][j + b[k]] == '#')c = 1;
		if (c == 0) f = 0;
	}
	Yes(f);
	return 0;
}

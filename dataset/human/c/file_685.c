#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* define */
#define Yes(X) puts ( X ? "Yes" : "No")
#define YES(X) puts ( X ? "YES" : "NO")
#define FOR(i, a, b) for ( int i = a; i < b ; i++)
#define REP(i, n) for ( int i = 0; i < n ; i++)
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max3(a, b, c) ((max((a), (b)) > (c)) ? max((a), (b)) : (c))
#define min3(a, b, c) ((min((a), (b)) < (c)) ? min((a), (b)) : (c))

/* const */
const int MOD = (int)1e9 + 7;

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
	int n, m, c = 0;
	char a[50][100], b[50][100];
	scanf("%d%d", &n, &m);
	REP(i, n)scanf("%s", &a[i]);
	REP(i, m)scanf("%s", &b[i]);
	REP(i, n - m + 1) {
		REP(j, n - m + 1) {
			int f = 1;
			REP(k, m) {
				REP(l, m) {
					if (a[i + k][j + l] != b[k][l])f = 0;
				}
			}
			if (f)c = 1;
		}
	}
	Yes(c);
	return 0;
}

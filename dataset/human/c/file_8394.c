#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* define*/
#define Yes(X) puts ( X ? "Yes" : "No")
#define YES(X) puts ( X ? "YES" : "NO")
#define FOR(i, a, b) for ( i = a; i < b ; i++)
#define REP(i, n) for ( i = 0; i < n ; i++)
#define DER(i, n) for ( i = n; n ; i--)
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max3(a, b, c) ((max((a), (b)) > (c)) ? max((a), (b)) : (c))
#define min3(a, b, c) ((min((a), (b)) < (c)) ? min((a), (b)) : (c))

/* const */
const int MOD = 1e9 + 7;

/* alias */
typedef long long ll;

/* function */
int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}
int cmp2(const void *a, const void *b) {
	return *(int*)b - *(int*)a;
}

/* main */
int i, j, k;

int main() {
	int n, k;
	char s[11];
	scanf("%d%s%d", &n, s, &k);
	REP(i, n) if (s[i] != s[k - 1])s[i] = '*';
	printf("%s", s);
	return 0;
}

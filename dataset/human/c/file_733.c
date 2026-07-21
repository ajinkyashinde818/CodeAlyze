#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* define*/
#define Yes(X) puts ( X ? "Yes" : "No")
#define YES(X) puts ( X ? "YES" : "NO")
#define FOR(i, a, b) for ( i = a, i < b ; i++)
#define REP(i, n) for ( i = 0; i < n ; i++)
#define DER(i, n) for ( i = 0; n ; i--)
#define max(a,b) (a > b) ? a : b
#define min(a,b) (a < b) ? a : b

/* const */
const int MOD = 1e9 + 7;

/* alias */
typedef long long ll;

/* function */
int cmp(const int *a, const int *b) {
	return *a - *b;
}
int cmp2(const int *a, const int *b) {
	return *b - *a;
}

//* main */

int main() {
	int n, i, j;
	ll c, r = 1;
	char s[100000];
	scanf("%d%s", &n, s);
	REP(i, 26) {
		c = 0;
		REP(j, n)if (s[j] == 'a' + i)c++;
		r *= c + 1;
		r %= MOD;
	}
	printf("%lld\n", r - 1);
	return 0;
}

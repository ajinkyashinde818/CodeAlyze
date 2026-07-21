#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
typedef long long LL;
typedef long double Lf;
#define Rep(i,a,n)for(int i=(int)(a);i<(int)(n);i++)
#define rep(i,n)Rep(i,0,n)
#define Ma(x,y) ((x)>(y)?(x):(y))
#define mi(x,y) ((x)<(y)?(x):(y))
#define MOD 1000000007
int acs(const void* a, const void* b) { return *(int*)a - *(int*)b; } // 1,2,3,4
int des(const void* a, const void* b) { return *(int*)b - *(int*)a; } // 8,7,6,5
int cmp_char(const void* a, const void* b) { return *(char*)a - *(char*)b; } // a,b,c,d
int cmp_str(const void* a, const void* b) { return strcmp(*(const char**)a, *(const char**)b); } // aaa,aab
//snippet
#define N 200009

int acsLL(const void* a, const void* b) { return*(LL*)a<*(LL*)b ? -1 : *(LL*)a> * (LL*)b ? 1 : 0; }

int main() {
	LL n, k, p[N], m[N], pl = 0, mn = 0, ans = 1, t;
	scanf("%lld%lld", &n, &k);
	rep(i, n) {
		scanf("%lld", &t);
		if (t >= 0)p[pl++] = t;
		else m[mn++] = -t;
	}
	qsort(p, pl, sizeof(LL), acsLL);
	qsort(m, mn, sizeof(LL), acsLL);


	if (n == k) {//all
		rep(i, mn)ans = ans * (MOD - m[i]) % MOD;
		rep(i, pl)ans = ans * p[i] % MOD;
	}
	else if (mn == n && k % 2) {//-
		rep(i, k)ans = ans * (MOD - m[i]) % MOD;
	}
	else {//normal
		while (k) {
			if (k >= 2 && mn >= 2 && (pl <= 1 || (pl >= 2 && m[mn - 1] * m[mn - 2] >= p[pl - 1] * p[pl - 2]))) {
				ans = ans * m[--mn] % MOD;
				ans = ans * m[--mn] % MOD;
				k = k - 2;
			}
			else {
				ans = ans * p[--pl] % MOD;
				k--;
			}
		}
	}
	printf("%lld", ans);
}

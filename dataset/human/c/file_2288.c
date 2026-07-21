#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define S_MAX 100
#define N_MAX 100000
#define M_MAX 200000
#define INF 10000000
#define MOD 1000000007
#define SMAP(a, b) ((a)!=(b))&&((a)^=((b)^=((a)^= (b))))

typedef unsigned long long ull;
typedef   signed long long dll;

int n, m;
int h, w;
int i, j, k;
int a, b;

char s[S_MAX + 1];

typedef struct {
	int in;
	int out;
} twoway;

void solve(){
	ull result = 0;
	ull prev;

	if (n < 1200) {
		puts("ABC");
	} else {
		puts("ARC");
	}

	return;
}

int main (void) {
	char *t;
	scanf("%d", &n);

	solve();
	return 0;
}

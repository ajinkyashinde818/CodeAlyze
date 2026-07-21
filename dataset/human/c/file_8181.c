#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N_MAX 200000
#define M_MAX 200000
#define INF 10000000
#define SMAP(a, b) ((a)!=(b))&&((a)^=((b)^=((a)^= (b))))

typedef unsigned long long ull;
typedef   signed long long dll;

int n, m;
int i, j, k;
int a;

typedef struct {
	int in;
	int out;
} twoway;

void deb(){
	return;
}

void solve(){
	int result;
	int prev = 0;

	return;
}

int main (void) {
	scanf("%d%d%d%d", &n, &m, &i, &j);
	a = n * m;
	if (i * j > a) a = i * j;
	printf("%d\n", a);

	solve();
	return 0;
}

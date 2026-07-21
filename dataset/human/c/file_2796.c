#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N_MAX 200000
#define INF 1145141919
#define SMAP(a, b) ((a)!=(b))&&((a)^=((b)^=((a)^= (b))))

typedef unsigned long long ull;

int i, j;

int n, m;
int k, s;

int h, w;

char str[N_MAX];

void solve(){
	return;
}

int main (void) {
	int result;
	scanf("%d%d", &k, &s);
	for (i = 0; i <= k; i++) {
		if (i > s) break;
		if (s - i > k * 2) continue;
		if (s - i > k) {
			result += 2 * k + i -s +1;
		} else {
			result += s - i + 1;
		}
	}
	printf("%d\n", result);
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long int sousu[100000];
int mod = 1000000007;

long long int rec(int x) {
	if (x < 0) {
		return 0;
	}
	else if (sousu[x] >= 0) {
		return sousu[x];
	}
	else if (x == 0) {
		sousu[x] = 1;
	}
	else if (x == 1) {
		if (sousu[x - 1] != 0) {
			sousu[x] = 2;
		}
		else {
			sousu[x] = 1;
		}
	}
	else {
		sousu[x] = (rec(x - 1) + rec(x - 2)) % mod;
	}
	return sousu[x];
}

int main() {
	int N, M, a, i;
	memset(sousu, -1, sizeof(sousu));
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &a);
		sousu[a - 1] = 0;
	}
	printf("%lld\n", rec(N - 1));
	return 0;
}

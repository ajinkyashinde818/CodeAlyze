#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
const long long mod = 1000000007;
//const long long mod = 998244353;

int main() {
	int N, K, S;
	scanf("%d", &N);
	scanf("%d", &K);
	scanf("%d", &S);
	for (int i = 0; i < N; i++) {
		if (i < K)printf("%d ", S);
		else printf("%d ", (S + 1) % 1000000000);
	}
	return 0;
}

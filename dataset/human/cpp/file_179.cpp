#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int R, G, B, N;

int main() {
	scanf("%d%d%d%d", &R, &G, &B, &N);

	ll tot = 0;
	for (int i = 0; i <= 3005; ++i) for (int j = 0; j <= 3005; ++j) {
		if (N - R*i - G*j >= 0 && (N - R*i - G*j) % B == 0) tot++;
	}

	printf("%lld\n", tot);
}

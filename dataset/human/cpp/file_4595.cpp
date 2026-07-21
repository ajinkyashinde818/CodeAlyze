#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int, int> P;

const int maxn = 50050;

int main() {
	int N, R;
	scanf("%d%d", &N, &R);
	if (N >= 10)
		printf("%d\n", R);
	else
	{
		int ans = R + 100 * (10 - N);
		printf("%d\n", ans);
	}
}

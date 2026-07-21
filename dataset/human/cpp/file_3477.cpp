#include <bits/stdc++.h>

using namespace std;
const int N = 22;

int main() {
	int n;
	scanf("%d", &n);
	long long res = 0;
	int mini = 1e9;
	bool odd = false;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		res += abs(a);
		if (a < 0)
			odd = !odd;
		mini = min(mini, abs(a));
	}
	if (!odd) {
		printf("%lld\n", res);
	} else {
		printf("%lld\n", res - mini * 2);
	}
	return 0;
}

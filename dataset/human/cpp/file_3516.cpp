#include <bits/stdc++.h>

using namespace std;

int n, a[100005];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	int neg = 0;
	long long sum = 0;
	int mn = 2e9;
	bool zero = 0;
	
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			neg++;
		}
		sum += abs(a[i]);
		mn = min(mn, abs(a[i]));
		if (a[i] == 0) zero = 1;
	}
	
	if (neg % 2 == 0 || zero) return 0 * printf("%lld\n", sum);
	printf("%lld\n", sum - 2LL * mn);
}

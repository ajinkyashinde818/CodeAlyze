#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int a[n];
	for (int i = 0; i < n; i++) a[i] = ri();
	
	int neg = 0;
	int min = 1000000001;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) neg++;
		min = std::min(min, std::abs(a[i]));
	}
	long long res = 0;
	for (int i = 0; i < n; i++) res += std::abs(a[i]);
	if (neg % 2) res -= min * 2;
	std::cout << res << std::endl;
	
	return 0;
}

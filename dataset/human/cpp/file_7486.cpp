#include<iostream>
#include<algorithm>
int n;
int a[200000];
long long sum, s;
long long ans = 1000000000000000, b;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	for (int j = 0; j < n-1; j++) {
		s += a[j];
		ans = std::min(ans, std::abs(sum-s*2));
	}
	std::cout << ans << "\n";
	system("pause");
	return 0;
}

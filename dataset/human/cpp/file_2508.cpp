#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

int main() {
	int n; scanf("%d", &n); std::vector<i64> a(n);
	for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
	
	auto dp = make_v<i64>(n + 1, 2);
	for(int i = 0; i <= n; i++) for(int j = 0; j < 2; j++) dp[i][j] = -(1LL << 60); dp[0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2; j++) {
			if(i == 0 and j == 1) continue;
			if(j) {
				dp[i + 1][0] = std::max(dp[i + 1][0], dp[i][j] - a[i]);
				if(i + 1 != n) dp[i + 1][1] = std::max(dp[i + 1][1], dp[i][j] + a[i]);
			} else {
				dp[i + 1][0] = std::max(dp[i + 1][0], dp[i][j] + a[i]);
				if(i + 1 != n) dp[i + 1][1] = std::max(dp[i + 1][1], dp[i][j] - a[i]);
			}
		}
	}
	
	printf("%lld\n", dp[n][0]);
	return 0;
}

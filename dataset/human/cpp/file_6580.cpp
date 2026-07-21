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
	int n; scanf("%d", &n);
	std::string s; cin >> s;

	const int MOD = 1e9 + 7;
	
	i64 ans = 1, tmp = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'W') {
			if(tmp % 2 == 0) {
				(ans *= (i64)tmp) %= MOD;
				tmp--;
			} else tmp++;
		} else {
			if(tmp % 2 == 1) {
				(ans *= (i64)tmp) %= MOD;
				tmp--;
			} else tmp++;
		}
		if(tmp < 0) ans = 0;
	}
	if(tmp != 0) ans = 0;
	for(i64 i = 1; i <= n; i++) (ans *= i) %= MOD;
	printf("%lld\n", ans);
	return 0;
}

#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int n; scanf("%d", &n);
	std::string s; cin >> s;
	
	std::vector<std::vector<int>> vec(26);
	for(int i = 0; i < s.size(); i++) vec[s[i] - 'a'].push_back(i);
	
	i64 ans = 1;
	const int MOD = 1e9 + 7;
	for(int i = 0; i < vec.size(); i++) {
		ans *= (i64)(vec[i].size() + 1);
		ans %= MOD;
	}
	printf("%lld\n", (ans + MOD - 1) % MOD);
	return 0;
}

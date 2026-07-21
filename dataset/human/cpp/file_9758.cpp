#include <bits/stdc++.h>

constexpr long long mod{1000000007};

int main()
{
	int n;
	std::string s;
	std::cin >> n >> s;
	int count[26]{};
	for (auto& e: s) count[e - 'a']++;
	long long ans{1};
	for (int i{}; i < 26; i++)
		ans = ans * (count[i] + 1) % mod;
	ans = (ans + mod - 1) % mod;

	printf("%lld\n", ans);
	
	return 0;
}

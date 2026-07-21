#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	
	if (n == 0) {
		cout << 0;
		return 0;
	}
	
	vector<int> count(26, 1);
	
	for (int i = 0; i < n; ++i) {
		++count[s[i] - 'a'];	
	}
	
	const int MOD = 1000000007;
	long long ans = 1;
	for (int i = 0; i < 26; ++i) {
		ans *= count[i];
		ans %= MOD;
	}
	
	ans -= 1;
	ans = ans % MOD;
	
   cout << ans;
   return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N;
	string S;
	cin >> N >> S;
	vector<long long> count(26, 0);
	for (int i = 0; i < N; ++i) {
		count[(int)(S[i] - 'a')]++;
		//cout << (int)(S[i] - 'a') << ":" << count[(int)(S[i] - 'a')] << endl;
	}
	long long mod = 1000000007;
	long long ans = mod + 1;
	for (int i = 0; i < 26; ++i) {
		//cout << i << ":" << count[i] << endl;
		ans = ((ans % mod) * (count[i] + 1)) % mod;
	}
	ans -= 1;
	cout << ans << endl;
	return 0;
}

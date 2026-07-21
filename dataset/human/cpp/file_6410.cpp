#include <string>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int main() {
	int N; string S;
	cin >> N >> S;
	string par;
	for (int i = 0; i < 2 * N; ++i) {
		if (i == 0) par += (S[i] == 'B' ? '(' : ')');
		else par += ((S[i] != S[i - 1] ? 1 : 0) ^ (par[i - 1] == '(' ? 0 : 1) ? '(' : ')');
	}
	int depth = 0, ans = 1;
	for (int i = 0; i < 2 * N; ++i) {
		if (par[i] == '(') ++depth, ans = 1LL * ans * depth % mod;
		else --depth;
		if (depth < 0) {
			ans = 0;
			break;
		}
	}
	if (depth != 0) ans = 0;
	for (int i = 1; i <= N; ++i) {
		ans = 1LL * ans * i % mod;
	}
	cout << ans << endl;
	return 0;
}

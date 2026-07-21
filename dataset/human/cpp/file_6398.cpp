#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

string s;
int n;

int main() {
//	freopen("inp.txt", "r", stdin);
	cin >> n;
	
	cin >> s;
	
	int cnt = 0;
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = ans * i % mod;
	}
	for (int i = 0; i < n * 2; i++) {
		if (i % 2 == 0) {
			if (s[i] == 'W') {
				s[i] = 'B';
			} else {
				s[i] = 'W';
			}
		}
		if (s[i] == 'B') {
			ans = ans * cnt % mod;
			cnt--;
		} else {
			cnt++;
		}
	}
	if (cnt != 0) {
		cout << 0;
		return 0;
	}
	cout << ans;
	
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;

vector<string>S;

struct INFO {
	int l, r, len;
};

int main() {
	ll N, L; cin >> N >> L;
	//N = 1;
	//L = 1e18;


	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		//s = string(1e5, '1');
		//for (int j = 0; j < 1e5; j += 2)s[j] = '0';
		S.push_back(s);
	}
	sort(S.begin(), S.end());

	ll ans = 0;

	queue<INFO>que;
	que.push(INFO({ 0, (int)S.size(), 0 }));
	while (que.size()) {
		INFO info = que.front(); que.pop();
		int l = info.l, r = info.r, len = info.len;

		bool flag1 = false, flag0 = false;
		int l0 = -1, r0, l1 = -1, r1;
		for (int i = l; i < r; i++) {
			if (S[i].size() == len);
			else if (S[i][len] == '0') {
				flag0 = true;
				if (l0 == -1)l0 = i;
				r0 = i + 1;
			}
			else if (S[i][len] == '1') {
				flag1 = true;
				if (l1 == -1)l1 = i;
				r1 = i + 1;
			}
		}

		if (l0 != -1)que.push(INFO({ l0, r0, len + 1 }));
		if (l1 != -1)que.push(INFO({ l1, r1, len + 1 }));

		if (flag0 && (flag1 == false)) {
			//cerr << S[l].substr(0, len) + "1" << endl;
			ll x = L - len;
			ll tmp = 1;
			while (x % 2 == 0) {
				tmp *= 2;
				x /= 2;
			}
			ans ^= tmp;
		}
		if ((flag0 == false) && flag1) {
			//cerr << S[l].substr(0, len) + "0" << endl;
			ll x = L - len;
			ll tmp = 1;
			while (x % 2 == 0) {
				tmp *= 2;
				x /= 2;
			}
			ans ^= tmp;
		}
	}

	cout << (ans ? "Alice" : "Bob") << endl;
	
	return 0;
}

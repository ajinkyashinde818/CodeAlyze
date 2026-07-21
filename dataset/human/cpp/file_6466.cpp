#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	string s;
	cin >> s;
	//string s(N*2,0);
	//cin >> s;
	/*for (int loop = 0; loop < 1 << (N * 2); loop++) {
		cout << "loop " << loop << endl;
		for (int j = 0; j < N * 2; j++) {
			if ((loop >> j) & 1)s[j] = 'W';
			else s[j] = 'B';
		}
		cout << s << endl;
		vector<long long int>by(N + 1, 1);
		for (int i = 1; i <= N; i++) {
			by[i] = by[i - 1] * i;
			by[i] %= MOD;
		}
		long long int ans = 1;
		long long int num = 0;
		bool flag = false;
		for (int i = 0; i < N * 2; i++) {
			if (!num&&s[i] == 'W') {
				//cout <<"not "<< 0 << endl;
				flag = true;
				//return 0;
				break;
			}
			if (s[i] == 'W') {
				if (num & 1) {
					num++;
				}
				else {
					ans *= num;
					ans %= MOD;
					num--;
				}
			}
			else {
				if (num & 1) {
					ans *= num;
					ans %= MOD;
					num--;
				}
				else {
					num++;
				}
			}
		}
		if (flag)continue;
		ans *= by[N];
		ans %= MOD;
		cout << ans << endl;
		vector<int>p(N * 2);
		for (int i = 0; i < N * 2; i++)p[i] = i;
		int ret = 0;
		do {
			vector<int>num(N * 2);
			for (int i = 0; i < N; i++) {
				for (int j = min(p[i * 2], p[i * 2 + 1]); j <= max(p[i * 2], p[i * 2 + 1]); i++)num[j]++;
			}
			int add = 1;
			for (int i = 0; i < N * 2; i++) {
				if (num[i] % 2 == 1 && s[i] == 'W')add = 0;
				if (num[i] % 2 == 0 && s[i] == 'B')add = 0;
			}
			ret += add;
		} while (next_permutation(p.begin(), p.end()));
		for (int i = 0; i < N; i++)ret /= 2;
		cout << ret << endl;
	}
	*/
	//*
	vector<long long int>by(N + 1, 1);
	for (int i = 1; i <= N; i++) {
		by[i] = by[i - 1] * i;
		by[i] %= MOD;
	}
	long long int ans = 1;
	long long int num = 0;
	for (int i = 0; i < N * 2; i++) {
		if (!num&&s[i] == 'W') {
			cout << 0 << endl;
			return 0;
		}
		if (s[i] == 'W') {
			if (num & 1) {
				num++;
			}
			else {
				ans *= num;
				ans %= MOD;
				num--;
			}
		}
		else {
			if (num & 1) {
				ans *= num;
				ans %= MOD;
				num--;
			}
			else {
				num++;
			}
		}
	}
	if (num) {
		cout << 0 << endl;
		return 0;
	}
	ans *= by[N];
	ans %= MOD;
	cout << ans << endl;
	//*/
}

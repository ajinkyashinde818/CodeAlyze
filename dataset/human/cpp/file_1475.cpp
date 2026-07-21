#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef pair< long long, long long > P;
typedef pair< long long, P > PP;
typedef pair< P, P > PPP;

const double DINF = 5e14, eps = 1e-10;
const long long MOD = 1e9 + 7, INF = 5e18;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()

ll n, l, r, cnt[100010];
bool fl = 0;
vector<int>ans[10000];

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) {
		if (n * 2 % i == 0) {
			if (n * 2 / i == i + 1) {
				fl = 1;
				l = i, r = i + 1;
				break;
			}
		}
	}
	if (!fl) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for (int j = 1;j <= l;j++) {
		ans[0].eb(j);
	}
	int now = 0, nex = 1, b = 1, nn = l + 1, t = 0;
	while (b <= l) {
		for (int i = 0;i < r - b;i++) {
			ans[nex].eb(ans[now][t + i]);
			nex++;
		}
		nex = b + 1;
		now++;
		for (int i = 0;i < l - b;i++) {
			ans[now].eb(nn + i);
		}
		nn += l - b;
		b++;
		t++;
	}
	cout << r << endl;
	for (int i = 0;i < r;i++) {
		cout << ans[i].size() << ' ';
		for (int j = 0;j < ans[i].size();j++) {
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}

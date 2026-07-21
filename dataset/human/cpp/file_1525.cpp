#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

const double eps = 1e-8;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main(){
	ll N;
	cin >> N;
	ll now = 0;
	ll n = 0;
	for (ll i = 1;true;i++) {
		now += i;
		n = i;
		if (now >= N)
			break;
	}
	if (now != N) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
		vector<vector<ll> > ans(n + 1, vector<ll>(n));
		ll cnt = 1;
		for (int k = 0;k < ans[0].size();k++) {
			ans[0][k] = cnt;
			cnt++;
		}
		for (int y = 1;y <= n;y++) {
			for (int k = 0;k < y;k++) {
				ans[y][k] = ans[k][y - 1];
			}
			for (int k = y;k < n;k++) {
				ans[y][k] = cnt;
				cnt++;
			}
		}
		cout << ans.size() << endl;
		for (int y = 0;y < ans.size();y++) {
			cout << ans[y].size() << " ";
			for (int x = 0;x < ans[y].size();x++) {
				cout << ans[y][x];
				if (x == (ll)ans[y].size() - 1)
					cout << endl;
				else
					cout << " ";
			}
		}
	}
	return 0;
}

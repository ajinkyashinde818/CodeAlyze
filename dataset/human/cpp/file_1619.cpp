#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const double PI = 3.1415926535897932384626433832795;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	ll t;
	for (int i = 0; i <= 1000; i++) {
		if (i * (i + 1) / 2 == n) {
			cout << "Yes" << endl;
			cout << i + 1 << endl;
			t = i;
			break;
		}

		if (n < i * (i + 1) / 2) {
			cout << "No" << endl;
			return 0;
		}
	}

	vector<vector<int>> a(t + 1, vector<int>(t));
	ll last = 0;
	for (int i = 0; i <= t; i++) {
		if (i == 0) {
			for (int j = 0; j  < t; j++) {
				a[i][j] = j + 1;
			}

			last = a[0][t - 1];
		} else {
			int j = 0;
			while (j < i) {
				a[i][j] = a[j][i - 1];
				j++;
			}

			int offset = 1;
			while (j < t) {
				a[i][j] = last + offset;
				j++;
				offset++;
			}
			last = a[i][t - 1];
		}
	}

	for (int i = 0; i <= t; i++) {
		cout << t << " ";
		for (int j = 0; j < t; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

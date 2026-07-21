#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <iomanip>

typedef long double ld;
typedef long long ll;

using namespace std;


/* TEMPLATE ENDS HERE */


#define MAXN (1 << 10)

set<int> a[MAXN];

int main() {
	cout << fixed << setprecision(12);	
	int n;
	cin >> n;
	for (ll i = 2; i <= 2 * n; i++) {
		if ((i * (i - 1)) / 2 == n) {
			int cur = 1;
			for (int ii = 0; ii < i; ii++) {
				for (int jj = 0; jj < ii; jj++) {
					a[ii].insert(cur);
					a[jj].insert(cur);
					cur++;
				}
			}
			cout << "Yes" << endl;
			cout << i << endl;
			for (int j = 0; j < i; j++) {
				cout << a[j].size() << " ";
				for (auto & e: a[j]) {
					cout << e << " ";
				}
				cout << endl;
			}
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}


ll MOD = ((ll)1e9 + 7);

struct mod {
	ll x;

	mod(ll tx = 0) {
		x = tx;
		x %= MOD;
	}
	
	mod& operator=(const ll & tx) {
		x = tx % MOD;
		return *this;
	}
	
	mod& operator=(const mod & m2) {
		x = m2.x;
		return *this;
	}

	mod operator+(const mod& m2) const {
		return mod((x + m2.x) % MOD);
	}

	mod& operator+=(const mod& m2) {
		x += m2.x;
		x %= MOD;
		return *this;
	}

	mod operator-(const mod & m2) const {
		return mod((x - m2.x + MOD) % MOD);
	}

	mod& operator-=(const mod & m2) {
		x -= m2.x;
		x = (x + MOD) % MOD;
		return *this;
	}

	mod operator*(const mod & m2) const {
		return mod((x * m2.x) % MOD);
	}

	mod& operator*=(const mod & m2) {
		x *= m2.x;
		x %= MOD;
		return *this;
	}

	mod mypow(ll k) const {
		mod ret = 1;
		mod cur = x;
		while (k) {
			if (k & 1) {
				ret *= cur;
			}
			cur *= cur;
			k >>= 1;
		}
		return ret;
	}

	mod inv() const {
		return mypow(MOD - 2);
	}

	mod operator/(const mod & m2) const {
		return (*this) * m2.inv();
	}

	mod& operator/=(const mod & m2) {
		x *= m2.inv().x;
		x %= MOD;
		return *this;
	}

	bool operator<(const mod & m2) const {
		return x < m2.x;
	}
};

ostream &operator<<(ostream & os, const mod & m) {
	return os << m.x;
}

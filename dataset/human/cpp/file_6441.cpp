//
//  main.cpp
//
 
#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
 
template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(ll i=(a)-1;i>=(b);i--)

struct Mod {
	static ll BASE;
	ll value = 0;
	static ll residue(ll value) { return (value % BASE + BASE) % BASE; }
	Mod()
	: value(0) {}
	Mod(ll value)
	: value(residue(value)) {}
	Mod operator+(const Mod& rhs) const { return Mod(value + rhs.value); }
	void operator+=(const Mod& rhs) { *this = *this + rhs; }
	Mod operator-(const Mod& rhs) const { return Mod(value - rhs.value); }
	void operator-=(const Mod& rhs) { *this = *this - rhs; }
	Mod operator*(const Mod& rhs) const { return Mod(value * rhs.value); }
	void operator*=(const Mod& rhs) { *this = *this * rhs; }
	Mod operator/(const Mod& rhs) const { return *this * rhs.inv(); }
	void operator/=(const Mod& rhs) { *this = *this / rhs; }
	Mod inv() const {
		if (value == 0) {
			assert(false);
			throw "[Mod::inv] div by zero";
		}
		ll ans, sub;
		ll d = Mod::gcd_with_coef(value, BASE, ans, sub);
		if (d != 1) {
			assert(false);
			throw "[Mod::inv] not invertible";
		}
		return ans;
	}
	static ll gcd_with_coef(ll x, ll y, ll& out_cx, ll& out_cy) {
		if (x < 0) {
			ll d = gcd_with_coef(-x, y, out_cx, out_cy);
			out_cx *= -1;
			return d;
		}
		if (y < 0) {
			ll d = gcd_with_coef(x, -y, out_cx, out_cy);
			out_cy *= -1;
			return d;
		}
		if (x > y) {
			return gcd_with_coef(y, x, out_cy, out_cx);
		}
		if (x == 0) {
			out_cx = 0;
			out_cy = 1;
			return y;
		}
		ll q = y / x;
		ll r = y % x;
		ll d = gcd_with_coef(r, x, out_cy, out_cx);
		out_cx -= q * out_cy;
		return d;
	}
	static vector<vector<Mod>> binom_table(ll n) {
		vector<vector<Mod>> ans;
		auto get = [&ans](ll r, ll k) -> Mod {
			if (r < 0 || k < 0 || k > r) {
				return Mod(0);
			} else {
				return ans[r][k];
			}
		};
		ans.push_back({Mod(1)});
		for (ll r = 1; r <= n; r++) {
			ans.push_back(vector<Mod>());
			for (ll k = 0; k <= r; k++) {
				ans[r].push_back(get(r - 1, k) + get(r - 1, k - 1));
			}
		}
		return ans;
	}
	static Mod power(Mod base, ll n) {
		assert(n >= 0);
		Mod ans(1);
		Mod pow(base);
		for (int i = 0; i < 63; i++) {
			if ((n >> i) & 1) {
				ans *= pow;
			}
			pow = pow * pow;
		}
		return ans;
	}
};
ll Mod::BASE = 1000000007;

int main() {
	ll N;
	string S;
	cin >> N;
	cin >> S;
	ll lines = 0;
	Mod ans = 1;
	rep(i,0,2*N) {
		ll col = (S[i] == 'B') ? 1 : 0;
		if ((lines + col) % 2 == 0) {
			if (lines == 0) {
				cout << 0 << endl;
				return 0;
			}
			ans *= lines;
			lines -= 1;
		} else {
			lines++;
		}
	}
	if (lines > 0) {
		cout << 0 << endl;
		return 0;
	}
	rep(n,1,N+1) {
		ans *= n;
	}
	cout << ans.value << endl;
}

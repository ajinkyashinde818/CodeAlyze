#include <bits/stdc++.h>

using namespace std;

template <class T>inline T updmax(T& a, T b) {return a = max(a, b);}
template <class T>inline T updmin(T& a, T b) {return a = min(a, b);}

template <unsigned long long mod> class modint {
  public:
	unsigned long long v;
	modint(const long long x = 0) : v(x % mod) {}
	modint operator+(const modint rhs) { return modint(*this) += rhs; }
	modint operator-(const modint rhs) { return modint(*this) -= rhs; }
	modint operator*(const modint rhs) { return modint(*this) *= rhs; }
	modint operator/(const modint rhs) { return modint(*this) /= rhs; }
	modint operator-() { return modint(mod - this->v); }
	modint& operator+=(const modint rhs) {
		v += rhs.v;
		if (v >= mod) v -= mod;
		return *this;
	}
	modint& operator-=(const modint rhs) {
		if (v < rhs.v) v += mod;
		v -= rhs.v;
		return *this;
	}
	modint& operator*=(const modint rhs) {
		v = v * rhs.v % mod;
		return *this;
	}
	modint inverse(modint a) {
		unsigned long long exp = mod - 2;
		modint ret(1ULL);
		while (exp) {
			if (exp % 2) { ret *= a; }
			a *= a;
			exp >>= 1;
		}
		return ret;
	}
	modint& operator/=(modint rhs) {
		(*this) *= inverse(rhs);
		return *this;
	}
	friend ostream& operator<<(ostream& os, modint& u) {
		os << u.v;
		return (os);
	}
	friend istream& operator>>(istream& is, modint& u) {
		is >> u.v;
		return (is);
	}
};

const int MOD = 1000000007;
using mint = modint<MOD>;

class Solution {
public:
	void solve() {
		int n;
		string s;
		cin >> n >> s;
		int c = 0;
		mint ret = 1;
		for(int i=0; i < 2*n; i++){
			if(s[i] == 'B'){
				if(c&1){
					ret *= c--;
				}else{
					c++;
				}
			}else{
				if(c&1){
					c++;
				}else{
					ret *= c--;
				}
			}
		}
		if(c != 0){
			cout << 0 << endl;
			return;
		}
		for(int i=0; i < n; i++)ret *= (i+1);
		cout << ret << endl;
		return;
	};
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Solution solution;
	solution.solve();
	return 0;
}

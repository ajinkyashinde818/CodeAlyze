#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

template<int64_t MOD> struct Mint {
    int64_t v;
    Mint(int64_t x) { v = x % MOD; if(v < 0)  v += MOD; }

    Mint operator-() { return Mint{-v}; };
    Mint operator+(Mint x) { return Mint(v + x.v); };
    Mint operator-(Mint x) { return Mint(v - x.v); };
    Mint operator*(Mint x) { return Mint(v * x.v); };
    Mint operator/(Mint x) { return Mint(v * pow(x.v, MOD-2).v); };

    Mint& operator+=(Mint x) { return *this = (*this + x); };
    Mint& operator-=(Mint x) { return *this = (*this - x); };
    Mint& operator*=(Mint x) { return *this = (*this * x); };
    Mint& operator/=(Mint x) { return *this = (*this / x); };

    static Mint pow(Mint base, int64_t exp) {
        if(exp == 0)  return Mint(1);
        return pow(base*base, exp/2) * (exp&1 ? base : Mint(1));
    }

    friend ostream& operator<<(ostream& os, Mint x) { return os << x.v; }
};

template<class T> struct Counting {
    void init(int64_t n) {
        _fact.assign(n+1, 1);
        for(int64_t i = 1; i <= n; i++)  _fact[i] = T(i) * _fact[i-1];
    }

    T fact(int64_t n) {
        assert(0 <= n && n < (int)_fact.size());
        return _fact[n];
    }

    T comb(int64_t n, int64_t k) {
        if(n < k)  return 0;
        return fact(n) / (fact(k) * fact(n-k));
    }

    private:
        vector<T> _fact;
};


#define NO() { cout << 0 << endl; return 0; }
const int64_t MOD = 1e9+7;
using mint = Mint<MOD>;
lint n;
string s;

int main() {
    cin >> n >> s;
    vector<char> lr;

    lint cnt = 0;
    mint ans(1);
    for(auto e : s) {
        bool left = (cnt + (e == 'B')) % 2;
        if(left)  cnt++;
        else      ans *= mint(cnt--);
        if(cnt < 0)  NO();
    }
    if(cnt != 0)  NO();

    Counting<mint> c;  c.init(100009);
    ans *= c.fact(n);
    cout << ans << endl;
}

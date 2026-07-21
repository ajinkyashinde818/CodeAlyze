#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1'000'000'007;

template<int mod> struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    ModInt &operator+=(const ModInt &p) { if((x += p.x) >= mod) x -= mod; return *this; }
    ModInt &operator-=(const ModInt &p) { if((x += mod-p.x) >= mod) x -= mod; return *this; }
    ModInt &operator*=(const ModInt &p) { x = (int)(1LL*x*p.x%mod); return *this; }
    ModInt &operator/=(const ModInt &p) { *this *= p.inverse(); return *this; }
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) { t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
        return ModInt(u);
    }
    ModInt pow(long long e){
        long long a = 1, p = x;
        while(e > 0) {
            if (e & 1) {a = (a * p) % mod; e--;}
            else {p = (p * p) % mod; e /= 2;}
        }
        return ModInt(a);
    }
    friend ostream &operator<<(ostream &os, const ModInt<mod> &p) {
        return os << p.x;
    }
    friend istream &operator>>(istream &is, ModInt<mod> &a) {
        long long x;
        is >> x;
        a = ModInt<mod>(x);
        return (is);
    }
};

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> a(2 * n); // 0 : L, 1 : R
    a[0] = 0;
    for (int i = 1; i < 2 * n; i++) {
        a[i] = a[i - 1] ^ (s[i] == s[i - 1]);
    }

    if (s[0] == 'W' or s[2 * n - 1] == 'W') {
        cout << 0 << '\n';
        return 0;
    }

    int val = 0;
    ModInt<MOD> ans = 1;
    for (int e : a) {
        if (e) ans *= val--;
        else val++;
    }

    for (int i = 0; i < n; i++) {
        ans *= (i + 1);
    }
    
    cout << ans * (val == 0) << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

using Int = long long;
struct ModInt {
    static Int mod;
    Int val;
    ModInt(Int v = 0) : val(v % mod) {}
    ModInt operator-() const { return ModInt(val ? mod - val : val); }
    ModInt &operator+=(ModInt a) {
        if ((val += a.val) >= mod) val -= mod;
        return *this;
    }
    ModInt &operator-=(ModInt a) {
        if ((val -= a.val) < 0) val += mod;
        return *this;
    }
    ModInt &operator*=(ModInt a) {
        val = (__uint128_t(val) * a.val) % mod;
        return *this;
    }
    ModInt &operator/=(ModInt a) {
        Int u = 1, v = a.val, s = 0, t = mod;
        while (v) {
            Int q = t / v;
            swap(s -= u * q, u);
            swap(t -= v * q, v);
        }
        a.val = (s < 0 ? s + mod : s);
        val /= t;
        return (*this) *= a;
    }
    ModInt inv() const { return ModInt(1) /= (*this); }
    bool operator<(ModInt x) const { return val < x.val; }
};
Int ModInt::mod = 1e9 + 7;

ostream &operator<<(ostream &os, ModInt a) {
    os << a.val;
    return os;
}
ModInt operator+(ModInt a, ModInt b) { return a += b; }
ModInt operator-(ModInt a, ModInt b) { return a -= b; }
ModInt operator*(ModInt a, ModInt b) { return a *= b; }
ModInt operator/(ModInt a, ModInt b) { return a /= b; }
ModInt pow(ModInt a, Int e) {
    ModInt x(1);
    for (; e > 0; e /= 2) {
        if (e % 2 == 1) x *= a;
        a *= a;
    }
    return x;
}

ModInt fact(Int x) {
    ModInt res = 1;
    while (1 < x) {
        res *= x;
        x--;
    }
    return res;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> v(n * 2);
    for (int i = 0; i < n * 2; i++) {
        v.at(i) = s.at(i) == 'B';
    }
    
    int l = 0, r = 0;
    Int cntL = 0;
    ModInt res = 1;
    for (int i = 0; i < n * 2; i++) {
        if (!(v.at(i) ^ (i % 2))) {
            res *= max((Int)0, cntL);
            cntL--;
            r++;
        }
        else {
            cntL++;
            l++;
        }
    }
    
    cout << (l == r ? res * fact(n) : 0) << endl;
}

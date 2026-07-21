#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

struct mint {
    lint v;
    lint _mod;
    mint() : v(0) {}
    mint(signed v, lint _mod = mod) : v(v), _mod(_mod) {}
    mint(lint t, lint _mod = mod) : _mod(_mod) {
        v = t % _mod;
        if (v < 0)
            v += _mod;
    }

    mint pow(lint k) {
        mint res(1), tmp(v);
        while (k) {
            if (k & 1)
                res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }
    static mint add_identity() { return mint(0); }
    static mint mul_identity() { return mint(1); }
    mint inv() { return pow(_mod - 2); }

    mint &operator+=(mint a) {
        v += a.v;
        if (v >= _mod)
            v -= _mod;
        return *this;
    }
    mint &operator-=(mint a) {
        v += _mod - a.v;
        if (v >= _mod)
            v -= _mod;
        return *this;
    }
    mint &operator*=(mint a) {
        v = v * a.v % _mod;
        return *this;
    }
    mint &operator/=(mint a) { return (*this) *= a.inv(); }

    mint operator+(mint a) const { return mint(v) += a; };
    mint operator-(mint a) const { return mint(v) -= a; };
    mint operator*(mint a) const { return mint(v) *= a; };
    mint operator/(mint a) const { return mint(v) /= a; };

    mint operator-() const { return v ? mint(_mod - v) : mint(v); }

    bool operator==(const mint a) const { return v == a.v; }
    bool operator!=(const mint a) const { return v != a.v; }
    bool operator<(const mint a) const { return v < a.v; }
};
ostream &operator<<(ostream &os, mint m) { return os << m.v; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    lint n;
    cin >> n;
    string s;
    cin >> s;
    mint ret  = 1;
    lint open = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (s[i] == 'B' && open % 2 == 0) {
            open++;
        } else if (s[i] == 'B' && open % 2 == 1) {
            ret *= open;
            open--;
        } else if (s[i] == 'W' && open % 2 == 0) {
            ret *= open;
            open--;
        } else if (s[i] == 'W' && open % 2 == 1) {
            open++;
        }
        if (open < 0 || open > n) {
            cout << 0 << "\n";
            return 0;
        }
    }
    if (open != 0) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        ret *= i;
    }
    cout << ret << "\n";
    return 0;
}

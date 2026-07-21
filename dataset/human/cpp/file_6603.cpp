#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
// #include <bits/stdc++.h>

template <long long mod>
struct modint {
    static const long long CACHE_SIZE = 1000000;

    long long x;

    modint<mod>(): x(0LL) {}
    modint<mod>(const long long _data) {
        if (_data < 0) {
            x = (_data % mod + mod) % mod;
        } else if (_data >= mod) {
            x = _data % mod;
        } else {
            x = _data;
        }
    }

    bool operator==(const modint<mod>& op) const {
        return x == op.x;
    }

    bool operator!=(const modint<mod>& op) const {
        return !((*this) == op);
    }

    modint<mod> operator-() const {
        if (x == 0) {
            return modint(0);
        }
        return modint(mod - x);
    }

    modint<mod> operator+(const modint<mod>& op) const {
        const long long newdata = x + op.x;
        if (newdata >= mod) {
            return modint<mod>(newdata - mod);
        } else {
            return modint<mod>(newdata);
        }
    }

    modint<mod> operator-(const modint<mod>& op) const {
        return *this + (-op);
    }

    modint<mod> operator*(const modint<mod>& op) const {
        return modint<mod>(x * op.x % mod);
    }

    modint<mod> pow(const long long n) const {
        if (n == 0) {
            return modint<mod>(1);
        }
        modint<mod> sq = pow(n / 2);
        if (n & 1) {
            return (*this) * sq * sq;
        } else {
            return sq * sq;
        }
    }

    modint<mod> inverse() const {
        return pow(mod - 2);
    }

    modint<mod> operator/(const modint<mod>& op) const {
        return (*this) * op.inverse();
    }

    friend modint<mod> operator/(const long long dividend, const modint<mod>& divisor) {
        return modint<mod>(dividend) / divisor;
    }

    static modint<mod> factorial(const long long n) {
        static modint<mod> cache[CACHE_SIZE] = {};

        if (cache[n].x != 0) {
            return cache[n];
        }

        if (n == 0) {
            return cache[0] = modint<mod>(1);
        } else {
            const modint<mod> retvar = modint<mod>(n) * factorial(n - 1);
            if (n < CACHE_SIZE) {
                cache[n] = retvar;
            }
            return retvar;
        }
    }

    static modint<mod> combination(const long long n, const long long k) {
        if (k < 0 || n < k) {
            return modint<mod>(0);
        }

        if (n < CACHE_SIZE) {
            return factorial(n) / (factorial(k) * factorial(n - k));
        }

        modint<mod> ret(1);
        for (int i = 1; i <= k; ++i) {
            ret = ret * modint<mod>(n - i + 1) / modint<mod>(i);
        }
        return ret;
    }
};

typedef modint<1000000007> mint;


using namespace std;
typedef long long li;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    li n;
    cin >> n;
    string s;
    cin >> s;

    mint ans = 1;
    li cur_open = 0;
    li cur_close = 0;
    for (int i = 0; i < 2 * n; ++i) {
        const li rem = cur_open - cur_close;
        const li op = rem % 2;
        const li st = (s[i] == 'W' ? 0 : 1);

        if (op == st) {
            // close
            ans = ans * rem;
            cur_close += 1;
        } else {
            // open
            cur_open += 1;
        }
    }
    ans = ans * mint::factorial(n);
    if (cur_close != cur_open) {
        ans = 0;
    }
    cout << ans.x << endl;
    return 0;
}

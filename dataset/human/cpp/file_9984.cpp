#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 1e9 + 7;

int64_t sum_mod (int64_t a, int64_t b) {
    return (a + b) % mod;
}

int64_t sub_mod (int64_t a, int64_t b) {
    return (a - b + mod) % mod;
}

int64_t mul_mod (int64_t a, int64_t b) {
    return (a * b) % mod;
}

int64_t pow_mod (int64_t a, int64_t b) {
    int64_t res = 1, t = a;
    while (b) {
        if (b & 1)
            res = mul_mod(res, t);
        t = mul_mod(t, t);
        b >>= 1;
    }
    return res;
}

int64_t div_mod (int64_t a, int64_t b) {
    return mul_mod(a, pow_mod(b, mod - 2));
}

signed main () {
    int n;
    string s;
    cin >> n >> s;
    int64_t ans = 0;
    map < char, int64_t > cnt;
    for (int i = 0; i < n; ++i) {
        int64_t pref = 1;
        for (auto pr: cnt) {
            if (pr.first != s[i])
                pref = mul_mod(pref, pr.second + 1);
        }
        ans = sum_mod(ans, pref);
        ++cnt[s[i]];
    }
    cout << ans << '\n';
}

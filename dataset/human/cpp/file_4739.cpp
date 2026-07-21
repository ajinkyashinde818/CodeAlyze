#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;

namespace Math {
// Generic modular integer.
    template<int MOD, typename IntType = int>
    struct GModint {
        IntType val;

        GModint() : val(0) {}

        GModint(int v, bool safe = false) { val = safe ? v : ((v % MOD) + MOD) % MOD; }

        GModint(ll v, bool safe = false) { val = safe ? v : ((v % MOD) + MOD) % MOD; }

        explicit operator bool() const { return val != 0; }

        const bool operator==(const GModint &g) const { return val == g.val; }

        const bool operator!=(const GModint &g) const { return val != g.val; }

        const GModint operator+=(const GModint &g) { return *this = *this + g; }

        const GModint operator-=(const GModint &g) { return *this = *this - g; }

        const GModint operator*=(const GModint &g) { return *this = *this * g; }

        const GModint operator/=(const GModint &g) { return *this = *this / g; }

        const GModint operator^=(const GModint &g) { return *this = *this ^ g; }

        const GModint operator-() const { return GModint(val == 0 ? 0 : MOD - val, true); }

        const GModint operator+(const GModint &g) const {
            ll newval = val + g.val;
            if (newval >= MOD)
                newval -= MOD;
            return GModint(newval, true);
        }

        const GModint operator-(const GModint &g) const { return *this + (-g); }

        const GModint operator*(const GModint &g) const { return GModint(1ll * val * g.val); }

        const GModint operator/(const GModint &g) const { return *this * g.inv(); }

        template<class T>
        const GModint operator^(const T t) const { return GModint(modpow(val, t, MOD)); }

        const GModint inv() const { return GModint(modinv(val, MOD)); }
    };

    using Modint = GModint<1000000007>;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, r; cin >> n >> r;

    if (n >= 10) {
        cout << r << endl;
    } else {
        cout << r + 100 * (10 - n) << endl;
    }
}

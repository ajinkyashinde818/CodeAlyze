#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template<long long mod>
struct mint {
private:
    long long x;
public:
    mint(long long x = 0) :x((mod + x) % mod) {}
    mint(std::string &s) {
        long long z = 0;
        for (int i = 0; i < s.size(); i++) {
            z *= 10;
            z += s[i] - '0';
            z %= mod;
        }
        this->x = z;
    }
    mint& operator+=(const mint &a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint &a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint &a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint& operator/=(const mint &a) {
        long long n = mod - 2;
        mint<mod> u = 1, b = a;
        while (n > 0) {
            if (n & 1) {
                u *= b;
            }
            b *= b;
            n >>= 1;
        }
        return *this *= u;
    }
    mint operator+(const mint &a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint &a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint &a) const {
        mint res(*this);
        return res *= a;
    }
    mint operator/(const mint &a) const {
        mint res(*this);
        return res /= a;
    }
    friend std::ostream& operator<<(std::ostream &os, const mint &n) {
        return os << n.x;
    }
    bool operator==(const mint &a) const {
        return this->x == a.x;
    }
};

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(2 * n);
    if (s[0] == 'W') {
        puts("0");
        return 0;
    }
    a[0] = 0;
    for (int i = 1; i < 2 * n; i++) {
        if (s[i] == s[i - 1]) {
            a[i] = 1 - a[i - 1];
        }
        else {
            a[i] = a[i - 1];
        }
    }
    int cnt = 0;
    constexpr int MOD = 1e9 + 7;
    mint<MOD> ans = 1;
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            if (cnt == 0) {
                puts("0");
                return 0;
            }
            ans *= cnt;
            cnt--;
        }
        else {
            cnt++;
        }
    }
    if (cnt > 0) {
        puts("0");
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        ans *= i;
    }
    cout << ans << endl;
    return 0;
}

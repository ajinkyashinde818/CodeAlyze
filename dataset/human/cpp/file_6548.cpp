#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <complex>
#include <bitset>
#include <functional>

using namespace std;
using ll=long long int;

template <typename T>
T powi(T a, ll n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret *= a; 
        a *= a;
        n >>= 1;
    }
    return ret;
}

template <ll mod>
class ModInt {
private:
    ll num;
public:
    ModInt() {};
    ModInt(ll n) { num = n % mod; }
    ModInt inv() const { return powi(*this, mod-2); }
    explicit operator ll() const { return num; }

    ModInt& operator+=(const ModInt& a) {
        num += a.num; 
        if (num >= mod) num -= mod; 
        return *this;
    }
    ModInt& operator-=(const ModInt& a) {
        if (num < a.num) num += mod;
        num -= a.num;
        return *this;
    }
    ModInt& operator*=(const ModInt& a) {
        num = num * a.num % mod;
        return *this;
    }
    ModInt& operator/=(const ModInt& a) { return *this *= a.inv(); }
    friend ModInt operator+(const ModInt& a, const ModInt& b) { return ModInt(a) += b; }
    friend ModInt operator-(const ModInt& a, const ModInt& b) { return ModInt(a) -= b; }
    friend ModInt operator*(const ModInt& a, const ModInt& b) { return ModInt(a) *= b; }
    friend ModInt operator/(const ModInt& a, const ModInt& b) { return ModInt(a) /= b; }

    friend ostream& operator<<(ostream& os, const ModInt& a) { return os << a.num; }
    friend istream& operator>>(istream& is, ModInt& a) {
        ll tmp;
        is >> tmp;
        a.num = tmp % mod;
        return is;
    }
};
using mint = ModInt<1000000007>;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<bool> fir(2 * n, false);

    int cur = 0;
    for (int i = 0; i < 2*n; ++i) {
        int t = cur + (s[i] == 'W' ? 0 : 1);
        if (t % 2 == 1) {
            fir[i] = true;
            ++cur;
        } else {
            cur--;
            if (cur < 0) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if (cur != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<array<int, 2>> cumu(2*n+1);
    cumu[0][0] = 0;
    cumu[0][1] = 0;
    for (int i = 0; i < 2*n; ++i) {
        cumu[i+1][0] = cumu[i][0];
        cumu[i+1][1] = cumu[i][1];

        cumu[i+1][fir[i]]++;
    }

    mint ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans *= i;
    }
    for (int i = 0; i < 2*n; ++i) {
        if (fir[i] == false) {
            int t = cumu[i+1][1] - cumu[i+1][0] + 1;
            ans *= t;
        }
    }

    cout << ans << endl;


    return 0;
}

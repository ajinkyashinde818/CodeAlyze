/* blog: https://misteer.hatenablog.com/entry/JSC2019-qual-C */

#include <iostream>
#include <vector>
#include <string>

template <int MOD>
class ModInt {
    using lint = long long;

public:
    int val;

    // constructor
    ModInt(lint v = 0) : val(v % MOD) {
        if (val < 0) val += MOD;
    };

    // assignment
    ModInt& operator=(const ModInt& x) {
        if (this != &x) { this->val = x.val; }
        return *this;
    }

    // unary operator
    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt operator~() const { return *this ^ (MOD - 2); }

    // increment / decrement
    ModInt& operator++() { return *this += 1; }
    ModInt& operator--() { return *this -= 1; }
    ModInt operator++(int) {
        ModInt before = *this;
        ++(*this);
        return before;
    }
    ModInt operator--(int) {
        ModInt before = *this;
        --(*this);
        return before;
    }

    // arithmetic
    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator%(const ModInt& x) const { return ModInt(*this) %= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
    ModInt operator^(const ModInt& x) const { return ModInt(*this) ^= x; }

    // compound assignment
    ModInt& operator+=(const ModInt& x) {
        if ((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& x) {
        if ((val -= x.val) < 0) val += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& x) {
        val = lint(val) * x.val % MOD;
        return *this;
    }
    ModInt& operator%=(const ModInt& x) {
        val %= x.val;
        return *this;
    }
    ModInt& operator/=(const ModInt& x) { return *this *= ~x; }
    ModInt& operator^=(const ModInt& x) {
        int n = x.val;
        ModInt b = *this;
        if (n < 0) n = -n, b = ~b;

        *this = 1;
        while (n > 0) {
            if (n & 1) *this *= b;
            n >>= 1;
            b *= b;
        }
        return *this;
    }

    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }
    bool operator<(const ModInt& b) const { return val < b.val; }
    bool operator<=(const ModInt& b) const { return val <= b.val; }
    bool operator>(const ModInt& b) const { return val > b.val; }
    bool operator>=(const ModInt& b) const { return val >= b.val; }

    // I/O
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
};


using namespace std;
using mint = ModInt<1000000007>;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int K = 0;
    mint ans = 1;
    for (auto c : S) {
        if ((c == 'W') == (K % 2 == 0)) {
            // 保留中のどれかの右端にする
            ans *= K;
            if ((--K) < 0) break;
        } else {
            // iを左端にする　右端は保留
            ++K;
        }
    }

    if (K != 0) {
        // invalidなマッチング
        cout << 0 << endl;
        return 0;
    }

    // N!を掛けて出力
    for (int i = 1; i <= N; ++i) ans *= i;
    cout << ans << endl;
    return 0;
}

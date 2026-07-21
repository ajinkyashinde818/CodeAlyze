#include <bits/stdc++.h>
using i64 = long long;

long long *fact, *inv;

template <typename T, typename U, typename V>
auto pow(T x_, U n_, V mod_) {
    std::common_type_t<T, U, V> ret = 1, x = x_, n = n_, mod = mod_;
    while(n > 0) {
        if ((n & 1) == 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

template <typename T, typename U>
auto inverse(T x, U p) { return pow(x, p - 2, p); }

void init_factorial(int n, long long mod) {
    fact = new long long[n + 1];
    inv = new long long[n + 1];
    fact[0] = 1;
    for (long long i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % mod;
    inv[n] = inverse(fact[n], mod);
    for (long long i = n; i > 0; i--) inv[i - 1] = inv[i] * i % mod;
}

int main() {
    constexpr i64 mod = 1000000007;
    int n;
    std::string s;
    std::cin >> n >> s;
    if (s.front() == 'W' || s.back() == 'W') {
        std::cout << 0 << std::endl;
        return 0;
    }
    init_factorial(n, mod);
    std::deque<std::pair<char, int>> q;
    std::vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        auto c = s[i];
        if (!q.empty() && q.back().first == c) {
            v[i] = 1;
            q.pop_back();
        } else {
            if (q.empty() && c == 'W') {
                std::cout << 0 << std::endl;
                return 0;
            }
            q.emplace_back(c, i);
        }
    }

    i64 ret = q.empty() ? fact[n] : 0, w = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (v[i]) ret = ret * w-- % mod;
        else w++;
    }

    std::cout << ret << std::endl;

    return 0;
}

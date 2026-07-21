#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <numeric>
#include <string>
#include <bitset>
#include <functional>

using ld = long double;
using vld = std::vector<ld>;
using vvld = std::vector<vld>;
using vvvld = std::vector<vvld>;
using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
using pll = std::pair<ll, ll>;
using vpll = std::vector<pll>;
using str = std::string;
using vstr = std::vector<str>;

template<typename T> bool chmin(T a, T &b) { return a < b ? b = a, true : false; }
template<typename T> bool chmax(T a, T &b) { return a > b ? b = a, true : false; }

constexpr ld PI = 3.141592653589793L;
constexpr ld EPS = std::numeric_limits<ld>::epsilon();

ll gcd(ll n, ll m) { return m ? gcd(m, n % m) : n; }
ll lcm(ll n, ll m) { return n / gcd(n, m) * m; }
bool is_prime(ll n) {
    if (n == 1) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

/*------------------------------------------------------------------------*/

void solve();

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::setprecision(15);

    solve();
}

void solve() {
    ll n, m;
    std::cin >> n >> m;

    vstr a(n), b(m);
    for (ll i = 0; i < n; i++) std::cin >> a[i];
    for (ll i = 0; i < m; i++) std::cin >> b[i];

    for (ll i = 0; i < n - m + 1; i++) for (ll j = 0; j < n - m + 1; j++) {
        bool flg = true;
        for (ll k = 0; k < m; k++) for (ll l = 0; l < m; l++)
            if (a[i + k][j + l] != b[k][l]) { flg = false; goto aaaaa; }
    aaaaa:
        if (flg) { std::cout << "Yes" << '\n'; return; }
    }

    std::cout << "No" << '\n';
}

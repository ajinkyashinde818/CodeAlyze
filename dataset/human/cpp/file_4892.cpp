#include <iostream>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

using ll = long long;

#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)

int gcd(int a, int b) { if (a < b) { a ^= b; b ^= a; a ^= b; } return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
    ll N, R;
    cin >> N >> R;
    ll r = (100 * (10 - N));
    cout << R + (r < 0 ? 0 : r) << endl;
    return 0;
}

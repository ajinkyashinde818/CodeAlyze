#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr static ll MOD = 1000000007ll;
constexpr static int INF = 1 << 28; // for x <= 10^9
constexpr static ll INFL = 1ll << 60; // for x <= 10^19
constexpr static double EPS = 1e-10;

int main() {
    int n, minA = INF, minusCount = 0;
    ll ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a < 0) {
            minusCount++;
        }

        int absA = abs(a);
        minA = min(minA, absA);

        ans += absA;
    }

    if (minusCount % 2 == 1) {
        ans -= 2 * minA;
    }

    cout << ans << endl;
}

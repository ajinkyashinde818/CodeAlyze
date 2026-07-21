#include <algorithm>
#include <list>
#include <cmath>
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pii;

const int SZ = 1000000 + 100;

ll n, k;

int solve() {
    ll ans;
    cin >> n >> k;
    if (n >= 10) {
        ans = k;
    } else {
        ans = k + 1000 - 100 * n;
    }
    cout << ans << endl;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);

    solve();

    return 0;
}

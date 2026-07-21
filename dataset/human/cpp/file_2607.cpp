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

using namespace std;
using ll=long long int;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e: a) cin >> e;

    int cnt = count_if(a.begin(), a.end(), [](int e){return e < 0;});

    ll ans = 0;
    for (auto &e: a) ans += abs(e);
    if (cnt % 2 == 1) {
        int d = 1e9+1;
        for (auto &e: a) d = min(d, abs(e));
        ans -= d * 2;
    }

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>
#include <map>
#include <cmath>
#include <type_traits>
using namespace std;

#define INF 1e18
#define int long long

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> sum(n);
    sum[0] = a[0];
    for(int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    int ans = INF;
    for(int i = 0; i < n - 1; i++) {
        int a = sum[i];
        int b = sum[n - 1] - sum[i];
        int diff = abs(a - b);
        ans = min(ans, diff);
    }

    cout << ans << endl;
    return 0;
}

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
#include <iomanip>
#include <numeric>
using namespace std;

#define INF 1e18
#define int long long

signed main() {
    int r, g, b, n;
    cin >> r >> g >> b >> n;

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            int k = n - i * r - j * g;
            if(k % b == 0 && 0 <= k && k <= n) ans++;
        }
    }


    cout << ans << endl;
    return 0;
}

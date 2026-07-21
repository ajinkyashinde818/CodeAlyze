#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const int MOD = 1e9 + 7;
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(8);
    double T, D; cin >> T >> D;
    double t1, t2; cin >> t1 >> t2;
    double d1, d2; cin >> d1 >> d2;
    double ans = INF;
    for(int i = 0; i <= D; i++)
    {
        for(int j = 0; j <= D; j++)
        {
            if(i == 0 and j == 0) continue;
            if(d1 * i + d2 * j > D) continue;;
            double a = (d1 * i) / 1000, b = (d2 * j) / 1000;
            double k = (t1 * a + t2 * b) / (a + b);
            ans = min(ans, abs(k - T));
        }
    }
    cout << ans << endl;
    return 0;
}

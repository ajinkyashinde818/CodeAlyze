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
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int r, g, b, n; cin >> r >> g >> b >> n;
    ll ans = 0;
    for(int i = 0; i <= 3000; i++)
    {
        for(int j = 0; j <= 3000; j++)
        {
            //k bo-ru
            ll k = n - i * r - j * g;
            if(k < 0) continue;;
            if(k % b != 0) continue;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 1e9;
constexpr ll linf = 1e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, r; cin >> n >> r;
    int ans = r;
    if (n < 10) ans += 100 * (10 - n);
    cout << ans << endl;
    return 0;
}

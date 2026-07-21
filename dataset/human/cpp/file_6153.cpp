#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int n;
    ll c;
    cin >> n >> c;

    vector<vector<ll>> sushi;
    sushi.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        ll x, v;
        cin >> x >> v;
        sushi.push_back({x, v});
    }
    sushi.push_back({c, 0});

    vector<ll> c_sumLeft(n + 1);
    for (int i = 1; i <= n; i++) {
        c_sumLeft[i] = c_sumLeft[i - 1] + sushi[i][1] - (sushi[i][0] - sushi[i - 1][0]);
    }
    vector<ll> c_sumRight(n + 1);
    for (int i = 1; i <= n; i++) {
        c_sumRight[i] = c_sumRight[i - 1] + sushi[n - i + 1][1] - (sushi[n - i + 2][0] - sushi[n - i + 1][0]);
    }

    vector<ll> maxc_sumLeft = c_sumLeft;
    for (int i = 1; i <= n; i++) maxc_sumLeft[i] = max(maxc_sumLeft[i], maxc_sumLeft[i - 1]);
    vector<ll> maxc_sumRight = c_sumRight;
    for (int i = 1; i <= n; i++) maxc_sumRight[i] = max(maxc_sumRight[i], maxc_sumRight[i - 1]);

    ll ret = 0;
    for (int left = 0; left <= n; left++) {
        ret = max(ret, (c_sumLeft[left] - sushi[left][0]) + maxc_sumRight[n - left]);
    }
    for (int right = 0; right <= n; right++) {
        ret = max(ret, (c_sumRight[right] + sushi[n - right + 1][0]) + maxc_sumLeft[n - right] - c);
    }

    cout << ret << endl;
    return 0;
}

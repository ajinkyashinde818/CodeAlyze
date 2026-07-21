#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, a[100005] = {};
    ll d[100005][2] = {};
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    d[1][0] = a[1];
    d[1][1] = -1ll * mod * mod;
    for (int i = 2; i <= n; i++) {
        d[i][0] = max(d[i - 1][0], d[i - 1][1]) + a[i];
        d[i][1] = max(d[i - 1][0] - a[i - 1] - a[i - 1], d[i - 1][1] + a[i - 1] + a[i - 1]) - a[i];
    }
    cout << max(d[n][0], d[n][1]);
}

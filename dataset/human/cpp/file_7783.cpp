#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> asum(n + 1);
    asum[0] = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        asum[i + 1] += asum[i] + a;
    }

    ll m = INF;
    for (int i = 1; i < n; i++) {
        m = min(m, abs((asum[i] - asum[0]) - (asum[n] - asum[i])));
    }
    cout << m << endl;
    return 0;
}

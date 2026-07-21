#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int INF = 1e9 + 1;
const ll LLINF = 1e18;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<ll> l(N + 2);
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
        l[i + 1] = l[i] + a[i];
    }

    ll ans = LLINF;
    for(int i = 1; i < N; ++i)
        ans = min(ans, abs(l[N] - 2 * l[i]));
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll judge(ll n) {
    ll ng = 0, ok = 10000000;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        if (mid * (mid - 1) >= 2 * n) ok = mid;
        else ng = mid;
    }
    if (ok * (ok - 1) == 2 * n) return ok;
    else return -1;
}

void solve(ll n, ll k) {
    ll cur = 1;
    vector< vector<ll> > ans(k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < i; j++) {
            ans[i].push_back(cur);
            ans[j].push_back(cur);
            cur++;
        }
    }

    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << ans[i].size();
        for (ll x : ans[i]) {
            cout << " " << x;
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll k = judge(n);
    if (k != -1) {
        cout << "Yes" << endl;
        solve(n, k);
    } else {
        cout << "No" << endl;
    }
    return 0;
}

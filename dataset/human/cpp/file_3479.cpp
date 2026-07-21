//https://atcoder.jp/contests/abc125/tasks/abc125_d
//D - Flipping Signs
//任意の二項の正負反転する操作になる
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
vector<ll> a;

int main() {
    cin >> n; a.resize(n);
    for (int i = 0; i < n; i++) scanf("%Ld", &a[i]);
    vector<ll> pos, neg;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<ll>());
    ll res = (ll)accumulate(pos.begin(), pos.end(), 0ll) - (ll)accumulate(neg.begin(), neg.end(), 0ll);
    if (neg.size()%2) {
        if (pos.size() != 0 && -neg[0] > pos[0]) res += -2*pos[0];
        else res += 2*neg[0];
    }
    cout << res << endl;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
using lc = complex<double>;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(32);
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &e: a) cin >> e, e--;
    for(auto &e: b) cin >> e, e--;


    vector<ll> ac(n), bc(n);
    for(auto &e: a) ac[e]++;
    for(auto &e: b) bc[e]++;

    vector<ll> cc(n);
    vector<vector<ll>> res(n);

    priority_queue<tuple<ll,ll>> q, r;
    for(ll i=0; i<n; i++) {
        if(bc[i]) q.push({ac[i]+bc[i], i}); 
        if(ac[i]) r.push({ac[i]+bc[i], i}); 
    }

    while(!q.empty()) {
        ll i = get<1>(q.top()); q.pop();

        if(r.empty()) {
            cout << "No" << endl;
            return 0;
        }

        ll j = get<1>(r.top()); r.pop();
        if(i == j) {
            if(r.empty()) {
                cout << "No" << endl;
                return 0;
            }
            ll jj = get<1>(r.top()); r.pop();
            r.push({(bc[j]+ac[j]), j}); 
            j = jj;
        }

        res[j].push_back(i); bc[i]--, ac[j]--;

        if(bc[i]) q.push({(bc[i]+ac[i]), i}); 
        if(ac[j]) r.push({(bc[j]+ac[j]), j}); 
    }

    cout << "Yes" << endl;
    for(auto &v: res) for(auto &e: v) cout << e+1 << ' ';
    cout << endl;
}

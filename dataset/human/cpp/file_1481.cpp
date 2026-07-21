#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
int main(){
    ll N;
    cin >> N;
    ll K = 1;
    while(1){
        if(K * (K + 1) == 2 * N){
            break;
        }else if(K * (K + 1) > 2 * N){
            cout << "No\n";
            return 0;
        }
        K++;
    }
    vector<vector<ll>> v(K + 1);
    ll now = 1;
    for(ll i = 0; i < K + 1; i++){
        ll tmp = now;
        while(v[i].size() < K){
            v[i].push_back(now);
            now++;
        }
        for(ll j = 0; j < now - tmp; j++){
            v[i + j + 1].push_back(tmp + j);
        }
    }
    cout << "Yes\n";
    cout << K + 1 << endl;
    for(auto u : v){
        cout << u.size();
        for(auto w : u) cout << " " << w;
        cout << endl;
    }
    return 0;
}

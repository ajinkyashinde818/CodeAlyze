#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;


int main(){
    int N;
    cin >> N;

    if(N == 1){
        cout << "Yes" << endl;
        cout << "2" << endl;
        cout << "1 1" << endl;
        cout << "1 1" << endl;
        return 0;
    }

    ll k = 3;
    while(k * (k - 1) / 2 < N){
        k++;
    }
    ll M = k * (k - 1) / 2;
    if(N != M){
        cout << "No" << endl;
        return 0;
    }

    vector<vector<ll>> ans(k);
    int v = 1;
    for(int i=0;i<k;i++){
        for(int j=i + 1;j<k;j++){
            ans[i].push_back(v);
            ans[j].push_back(v);
            v++;
        }
    }
    cout << "Yes" << endl;
    cout << k << endl;
    for(int i=0;i<k;i++){
        cout << ans[i].size();
        for(auto j : ans[i]){
            cout << " " << j;
        }
        cout << endl;
    }

    return 0;
}

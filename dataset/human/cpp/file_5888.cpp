#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e5 + 5;

int n;
ll C;
ll X[mx], K[mx + mx];

void input(){
    cin >> n >> C;
    for(int i = 1; i <= n; i++){
        cin >> X[i] >> K[i];
        K[i] += K[i-1];
    }
}

ll cwise(){
    ll ans = 0, cal = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, K[i] - X[i]);
    }
    return ans;
}

ll awise(){
    ll ans = 0, cal = 0;
    for(int i = n; i >= 1; i--){
        ans = max(ans, K[n] - K[i-1] + X[i] - C);
    }
    return ans;
}

ll cawise(){
    ll ans = 0, rf = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, K[n] - C - K[i-1] + X[i] + rf);
        rf = max(rf, K[i] - 2LL * X[i]);
    }
    return ans;
}

ll acwise(){
    ll ans = 0, rf = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, K[n] - 2LL * C - K[i-1] + 2LL * X[i] + rf);
        rf = max(rf, K[i] - X[i]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    cout << max({cwise(), awise(), acwise(), cawise()}) << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    ll n, c;
    cin >> n >> c;
    vector<ll> x(n),v(n);
    vector<ll> cv(n,0),anticv(n,0);
    vector<ll> cvm(n,0),anticvm(n,0);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> v[i];
    }
    cv[0] = v[0];
    anticv[0] = v[n-1];
    for(int i = 1; i < n; i++){
        cv[i] = cv[i-1] + v[i];
        anticv[i] = anticv[i-1] + v[n-1-i];
    }
    for(int i = 0; i < n; i++){
        cv[i] -= x[i];
        anticv[i] -= c-x[n-1-i];
    }
    cvm[0] = cv[0]; anticvm[0] = anticv[0];
    for(int i = 1; i < n; i++){
        cvm[i] = max(cvm[i-1],cv[i]);
        anticvm[i] = max(anticvm[i-1],anticv[i]);
    }

    ll cv_max = cvm[n-1];
    ll acv_max = anticvm[n-1];
    ll ans = max(cv_max, acv_max);

    if(ans < 0){
        cout << "0" << endl;
        return 0;
    }

    ll t;
    for(int i = 0; i < n-1; i++){
        t = anticv[i] - (c-x[n-1-i]) + cvm[n-2-i];
        ans = max(ans, t);
    }
    for(int i = 0; i < n-1; i++){
        t = cv[i] - (x[i]) + anticvm[n-2-i];
        ans = max(ans, t);
    }


    cout << ans << endl;

    return 0;

}

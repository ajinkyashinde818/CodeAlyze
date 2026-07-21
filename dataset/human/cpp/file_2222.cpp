#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    int neg = 0;
    int zero = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(v[i] < 0) neg++;
        if(v[i] == 0) zero++;
    }
    ll mi = 1e9;
    for(int i=0; i<n; i++){
        mi = min(mi, abs(v[i]));
    }

    ll ans = 0;
    for(int i=0; i<n; i++) ans += abs(v[i]);
    bool flag = false;
    if(neg%2 == 0) flag = true;
    if(neg%2 != 0 && zero != 0) flag = true;
    if(flag == false) ans -= 2*abs(mi);
    cout << ans << endl;
}

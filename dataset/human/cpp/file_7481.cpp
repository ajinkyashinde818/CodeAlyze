//omajinai
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//omajinai

int main(){

    // omajinai
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // omajinai

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0;i < n;i ++){
        cin >> a.at(i);
    }

    ll sum = 0;
    for(ll i = 0;i < n;i ++){
        sum += a.at(i);
    }

    ll b = sum;
    ll c = 0;
    ll ans = 100000000000000;

    for(ll i = 0;i < n-1;i ++){
        b -= a.at(i);
        c += a.at(i);
        ans = min(ans,abs(b-c));
    }

    cout << ans << endl;
}

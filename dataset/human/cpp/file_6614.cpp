#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int MOD = 1e9 + 7;
ll factorial(ll n){
    ll res = 1;
    for(ll i = n; i > 0; --i){
        (res *= i) %= MOD;
    }
    return res;
}

int main(){

    ll N; string S; cin >> N >> S;
    vector<bool> d(2*N, false); // let L = false & R = true

    for(int i = 0; i < 2*N; ++i) 
        if((i % 2 == 0 && S[i] == 'W') || (i % 2 && S[i] == 'B')) 
            d[i]  = true;
    
    ll ans = 1, lsum = 0;
    for(int i = 0; i < 2*N; ++i)
        if(d[i]){
            if(lsum == 0){
                cout << 0 << endl;
                return 0;
            }
            (ans *= lsum) %= MOD;
            --lsum;
        }else ++lsum;
    
    if(lsum > 0) cout << 0 << endl;
    else cout << ans*factorial(N)%MOD << endl;

    return 0;
}

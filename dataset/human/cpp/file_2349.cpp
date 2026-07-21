#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

ll mypow(ll x,ll n){
    ll ret = 1;
    while(n > 0){
        if(n&1){
            ret = (ret*x)%MOD;
        }
        x = (x*x)%MOD;
        n >>= 1;
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    ll n;
    cin >> n;

    vector<ll> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    bool even = true;

    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            even = !even;
        }
    }

    vector<ll> aba(n);
    for(int i = 0; i < n; i++){
        aba[i] = abs(a[i]);
    }

    sort(aba.begin(),aba.end());

    ll ans = 0;

    for(int i = 0; i < n; i++){
        ans += aba[i];
    }

    if(!even){
        ans -= aba[0]*2;
    }

    cout << ans << endl;

    return 0;
}

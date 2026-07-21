#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
//ll GCD(ll x,ll y){
//    if(y == 0) return x;
//    else return GCD(y,x%y);
//}

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;



int main() {
    int n; cin >> n;
    vector<int> v;
    ll a=0,b,total = LLONG_MAX;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        a += x;
        v.push_back(x);
    }
    
    a -= v[0];
    b = v[0];
    for(int i = 1;i < n-1;i++){
        total = min(total,abs(a-b));
        a -= v[i];
        b += v[i];
    }
    
    total = min(total,abs(a-b));
    cout << total;
   
}

#include<bits/stdc++.h>
#include<iomanip>

using namespace std;
using ll = long long;
constexpr int mod = 1e9+7;
constexpr int md = mod;
constexpr int MOD = mod;
constexpr ll inf = 1e9+5;
const int MAX=510000;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin>>n;
    vector<ll> v(n);
    ll sum = 0;
    int minuscount  = 0;
    ll mi = 1e10;
    for(auto & a : v){
        cin>>a;
        if(a <0)minuscount++;
        sum += abs(a);
        mi = min(abs(a),mi);
    }
    if(minuscount%2){
        cout << 1LL*(sum - 2LL*mi) << endl;
    }else{
        cout << sum << endl;
    }
    return 0;
}

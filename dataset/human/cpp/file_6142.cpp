#include<bits/stdc++.h>
#include<iomanip>
#include<numeric>

using namespace std;
using ll = long long;
constexpr int mo = 1e9+7;
constexpr int  mod = mo;
constexpr int inf = 1<<30;
int main(){
    int n;
    ll c;
    cin>>n>>c;
    vector<pair<ll,ll>> sushi(n);
    for(auto &a : sushi) cin>>a.first >> a.second;
    vector<pair<ll,ll>> lsum(n+1),rsum(n+1);
    
    for(int i=n-1;i>=0;--i){
        lsum[i] = {c-sushi[i].first,lsum[i+1].second + sushi[i].second}; 
    }
    rsum[0] = sushi[0];
    for(int i=0;i<n;++i){
        rsum[i+1] = {sushi[i+1].first,rsum[i].second + sushi[i+1].second};
    }
    vector<ll> lg(n+1),rg(n+1);
    for(int i=1;i<n;++i){
        rg[i] = max(rg[i-1],rsum[i-1].second - rsum[i-1].first);
    }
    for(int i=n-2;i>=0;--i){
        lg[i] = max(lg[i+1],lsum[i+1].second - lsum[i+1].first);
    }
    ll sum = 0ll;
    for(int i=0;i<n;++i){
        sum = max(sum,rsum[i].second - rsum[i].first + max(0ll,lg[i] - rsum[i].first));
    }
    for(int i=n-1;i>=0;--i){
        sum = max(sum,lsum[i].second - lsum[i].first + max(0ll,rg[i] - lsum[i].first));
    }
    cout << sum << endl;
    return 0;
}

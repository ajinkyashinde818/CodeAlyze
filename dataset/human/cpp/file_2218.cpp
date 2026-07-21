#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;

typedef unordered_map<ll, unordered_map<ll, ll>> graph;

const ll INF = 1ll << 50;
const ll mod = 1000000007;

ll n;
v1 a;
ll sign = 0;
ll unsign = 0;
ll zero = 0;
ll ans = 0;

int main(){
    cin >> n;
    a = v1(n);
    for(ll i = 0;i < n;i++){
        cin >> a[i];
    }
    for(ll i = 0;i < n;i++){
        if(a[i] > 0){
            sign++;
        }else if(a[i] < 0){
            unsign++;
        }else{
            zero++;
        }
    }
    if(zero > 0){
        for(ll i = 0;i < n;i++){
            ans += abs(a[i]);
        }
    }else if(unsign % 2 == 0){
        for(ll i = 0;i < n;i++){
            ans += abs(a[i]);
        }
    }else{
        ll min_a = abs(a[0]);
        for(ll i = 0;i < n;i++){
            ans += abs(a[i]);
            min_a = min(min_a, abs(a[i]));
        }
        ans -= min_a * 2;
    }
    cout << ans << endl;



}

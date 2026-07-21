#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll zero = 0;
ll INF = 10000000000;

int main(void){
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(ll i = 0; i<N; i++){
        cin >> a.at(i);
    }
    ll cnt = 0;
    ll cntzero = 0;
    for(ll i: a){
        if(i < 0){
            cnt++;
        }
        else if(i == 0){
            cntzero++;
        }
    }
    ll ans = 0;
    ll minabs = 10000000000;
    if(cnt % 2 == 0 || cntzero >= 1){
        for(ll i: a){
            ans += abs(i); 
        }
        printf("%lld",ans);
    }
    else{
        for(ll i: a){
            minabs = min(minabs, abs(i));
        }
        for(ll i: a){
            ans += abs(i); 
        }
        ans -= minabs*2;
        printf("%lld",ans);
        
    }
    
}

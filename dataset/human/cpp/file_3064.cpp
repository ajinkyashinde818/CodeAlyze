#include<bits/stdc++.h>
#include <iomanip>
#include <iostream>
using namespace std;
using ll = long long;
ll INF = 9999999999999999;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll gcf(ll a, ll b){
    if(b == 0) return a;
    return gcf(b, a%b);
}

ll lcm(ll a, ll b){
    ll g = gcf(a, b);
    return a/g * b;
}
int main(void){
    int N; cin >> N;
    vector<ll> A(N); for(int i = 0; i < N; i++) cin >> A[i];
    
    ll ans = 0;
    int minas_count = 0;
    for(int i = 0; i < N; i++){
        ans += max(A[i], -A[i]);
        if(A[i] < 0) minas_count++;
    }
    
    if(minas_count % 2 == 0){
        cout << ans << endl;
        return 0;
    }
    else{
        ll abs_min = 99999999999999;
        for(int i = 0; i < N; i++){
            abs_min = min(abs_min, abs(A[i]));
        }
        ans -= 2 * abs_min;
        cout << ans << endl;
        return 0;
    }
}

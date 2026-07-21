#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll>P;

int main(){
    
    ll n;
    cin >> n;
    vector<P>v;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        v.push_back(P(abs(a), a));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vll A(n);
    for(int i = 0; i < n; i++)A[i] = v[i].second;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i+1==n){
            ans += A[i];
            break;
        }
        if(A[i] > 0){
            ans += A[i];
            continue;
        }
        A[i] = -A[i];
        A[i+1] = -A[i+1];
        ans += A[i];
    }
    cout << ans << endl;
    
    return 0;
}

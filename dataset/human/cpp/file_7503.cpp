#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main(void){
    int N;
    cin >> N;
    vector<ll> a(N);
    ll t=0;
    for(int i=0; i<N;i++){
        cin >> a[i];
        t += a[i];
    }
    ll x = a[0];
    ll y = t - x;
    ll ans = abs(x-y);
    for(int i=1;i<N-1;i++){
        x += a[i];
        y -= a[i];
        ans = min(ans, abs(x-y));
    }
    cout << ans <<endl;
    return 0;
}

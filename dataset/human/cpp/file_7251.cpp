#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    ll a[n];
    ll sum = 0, p = 0;
    ll ans = 1000000000000000000;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < n-1; i++){
        p += a[i];
        ans = min(ans,abs(sum-2*p));
    }
    cout << ans << endl;

    return 0;
}

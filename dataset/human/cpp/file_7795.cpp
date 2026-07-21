#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    int n;
    cin >> n;
    ll a[210000];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    ll x=a[0], y=0;
    for(int i=1; i<n; i++){
        y += a[i];
    }
    ll ans = abs(x-y);
    for(int i=1; i<n-1; i++){
        x += a[i];
        y -= a[i];
        ans = min(ans, abs(x-y));
    }
    cout << ans << endl;
    return 0;
}

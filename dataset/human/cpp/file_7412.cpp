#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    ll suma=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        suma+=a[i];
    }
    ll sums=a[0];
    suma-=a[0];

    ll ans=abs(suma-sums);
    for(int i = 1; i < n-1; i++) {
        sums+=a[i];
        suma-=a[i];
        ll tans=abs(suma-sums);
        ans=min(ans,tans);
    }
    cout << ans << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n, asum = 0;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for(ll i = 0;i < n;i++){
        cin >> a[i];
        if(i != 0){
            b[i] = b[i - 1];
        }
        b[i] += a[i];
        asum += a[i];
    }
    for(ll i = n - 1;i >= 0;i--){
        if(i != n - 1){
            c[i] += c[i + 1];
        }
        c[i] += a[i];
    }

    ll ans = 0, min = abs(b[0] - c[1]);
    for(ll i = 1;i < n;i++){
        if(abs(b[i - 1] - c[i]) < min){
            min = abs(b[i - 1] - c[i]);
        }
    }

    cout << min;

    return 0;
}

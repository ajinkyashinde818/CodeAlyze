#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, sum = 0;
    cin >> n;
    
    ll a[n];
    for(ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    
    for(int i = 1; i < n; ++i)
    {
        sum += a[i];
    }
    
    ll tmp = a[0];
    ll ans = abs(tmp - sum);
    
    for(ll i = 1; i < n - 1; ++i)
    {
        tmp += a[i];
        sum -= a[i];
        ans = min(ans, abs(tmp - sum));
    }
    
    cout << ans << endl;
}

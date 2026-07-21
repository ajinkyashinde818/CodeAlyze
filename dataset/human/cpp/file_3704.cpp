#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    int minus_cnt = 0;
    ll absmin = 1e10;
    int pos = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] <= 0) minus_cnt++;
        if(abs(a[i]) < absmin)
        {
            absmin = abs(a[i]);
            pos = i;
        }
    }
    ll ans = 0;
    if(minus_cnt % 2 == 0)
    {
        for(int i = 0; i < n; i++)
        {
            ans += abs(a[i]);
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(i == pos)
            {
                ans -= abs(a[i]);
            }
            else
            {
                ans += abs(a[i]);
            }
        }
    }
    cout << ans << endl;
}

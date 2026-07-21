#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5;
long long x[N],v[N],lm[N],rm[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long c,sum=0;
    cin >> n >> c;
    for (int i = 1; i<=n; i++)
        cin >> x[i] >> v[i];
    long long m = 0;
    for (int i = 1; i<=n; i++)
    {
        sum+=v[i];
        lm[i] = max(sum-x[i],m);
        m = max(m,lm[i]);
    }
    sum = m = 0;
    for (int i = n; i>=1; i--)
    {
        sum+=v[i];
        rm[i] = max(sum-(c-x[i]),m);
        m = max(m,rm[i]);
    }
    long long ans = 0;
    for (int i = 1; i<=n; i++)
    {
        ans = max(ans,lm[i]);
        ans = max(ans,rm[i]);
    }
    for (int i = 1; i<=n; i++)
    {
        ans = max(ans,lm[i]-x[i]+rm[i+1]);
        ans = max(ans,rm[i]-(c-x[i])+lm[i-1]);
    }
    cout << ans;
}

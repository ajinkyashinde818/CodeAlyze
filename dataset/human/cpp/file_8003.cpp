#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int A[N];
LL csum[N];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;

    LL sum = 0, ans = LLONG_MAX;
    for(int i = 1; i <= n; i++)
    {
        cin>>A[i];
        sum += A[i];
        csum[i] = sum;
    }

    for(int i = 1; i < n; i++)
    {
        LL x = csum[i];
        LL y = sum - x;
        ans = min(ans, abs(x - y));
    }

    cout<<ans<<"\n";

    return 0;
}

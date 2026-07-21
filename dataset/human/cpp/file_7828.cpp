#include<bits/stdc++.h>
using namespace std;

long long a[200005];
long long b[200005];
long long c[200005];
int main()
{
    int n;

    cin >> n;

    for(int i = 1 ; i<=n ; i++)
    {
        cin >> a[i];
        b[i] = b[i-1]+a[i];
    }
    for(int i = n ; i>=1 ; i--)
    {
        c[i] = c[i+1]+a[i];
    }

    long long ans = 10100100100100100;


    for(int i = 1 ; i<n ; i++)
    {
        //cout << abs(b[i] - c[i+1]) << endl;
        ans = min(ans , abs(b[i] - c[i+1]));
    }
    cout << ans;
}

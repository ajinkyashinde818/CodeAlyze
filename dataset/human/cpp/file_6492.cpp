#include <bits/stdc++.h>
using namespace std;
const int base=1e9+7;
string s;long long n,kq,x,dem;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.inp", "r", stdin);
    //freopen("ou.out", "w", stdout);
    cin>>n>>s;
    kq=1;
    x=0;dem=0;
    for (long long i=2*n-1;i>=0;i--)
    {
        if (i%2&&s[i]=='B') x++;
        else if (i%2==0&&s[i]=='W') x++;
        else {kq=(kq*x)%base; x--;dem++;}

    }
    if (dem!=n) cout<<0;
    else
    {
        for (int i=2;i<=n;i++) kq=(kq*i)%base;
        cout<<kq;
    }

    return 0;
}

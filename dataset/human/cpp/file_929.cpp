#include <bits/stdc++.h>
using namespace std;
//o(N^2)まで

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,r,g,b,nr=0,ng=0,nb=0,sum=0,ans=0; 
    cin >> r >> g >> b >> n;
    nr=n/r; ng=n/g; nb=n/b;
    if (n%b==0) ans++;

    for (int i = 0; i<=nr; i++)
    {
        for (int j =0; j<=ng; j++)
        {
            if (i==0 && j==0) continue;
            sum = (r*i+g*j);
            if (sum<=n && (n-sum)%b==0)ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

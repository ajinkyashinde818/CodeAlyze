#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int r,g,b,n;cin>>r>>g>>b>>n;

    int ans=0;

    int rm=n/r;
    for(int i=rm;i>=0;i--)
    {
        int nr=n-i*r;
        int gm=nr/g;
        for(int j=gm;j>=0;j--)
        {
            int ng=nr-j*g;
            if(ng%b==0)ans++;
        }
    }

    cout<<ans<<"\n";

    return 0;
}

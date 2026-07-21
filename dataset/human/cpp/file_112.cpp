#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int ans = 0;
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j+i<=n;++j)
        {
            if(i%r==0&&j%g==0&&(n-i-j)%b==0)
            {
                ans++;
            }
        }
    }
    cout<<ans;
}

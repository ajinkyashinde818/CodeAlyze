#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r,g,b,n;
    int c=0;
    cin>>r>>g>>b>>n;
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            long long gg=i*r+j*g;
            gg=n-gg;
            if(gg>=0&&gg%b==0)
            {
                c++;
            }
        }
    }
    cout<<c<<endl;
}

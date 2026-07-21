#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,g,b,n,s,k;
    cin>>r>>g>>b>>n;
    k=0;
    for(int i=0;i<=n/r;i++)
    {
        for(int j=0;j<=(n-i*r)/g;j++)
        {
            if((n-i*r-j*g)%b==0)
                k++;
        }
    }
    cout<<k;
    return 0;
}

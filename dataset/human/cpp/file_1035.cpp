#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,g,b,n,i,j,k=0;
    cin>>r>>g>>b>>n;
    for(i=0;i*r<=n;i++)
        for(j=0;j*g+i*r<=n;j++)
            if((n-i*r-j*g)%b==0)
                k++;
    cout<<k;
    return 0;
}

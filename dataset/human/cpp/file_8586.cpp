#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,k,p,q;
    cin>>n>>m;
    string big[n+1],small[m+1];
    string tmp;
    for(i=1;i<=n;i++)
    cin>>big[i];
    for(i=1;i<=m;i++)
    cin>>small[i];
    int flag = 0;
    for(i=1;i<=n-m+1;i++)
    for(j=0;j<=n-m;j++)
    {
        tmp = big[i].substr(j,m);
        if(tmp==small[1])
        {
            for(p=2;p<=m;p++)
            {
                tmp = big[p+i-1].substr(j,m);
                
                if(small[p]!=tmp)
                break;
            }
            if(p==m+1)
            flag = 1;
        
            if(flag)
            break;
        }
    }
    if(flag)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
       
}

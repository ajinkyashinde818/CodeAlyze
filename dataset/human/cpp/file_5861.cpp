#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
long long c;
long long x[100011];
long long v[100011];

long long p[100011][3];
long long mp[100011][3];
long long q[100011][3];
long long mq[100011][3];

int main()
{
    int i,j,k;
    
    scanf("%d %lld",&n,&c);
    
    for(i=1;i<=n;i++)
    {
         scanf("%lld %lld",&x[i],&v[i]);
    }
    
    long long s=0;
    for(i=1;i<=n;i++)
    {
        s+=v[i];
        p[i][1]=s-x[i];
        p[i][2]=s-x[i]*2ll;
        
        mp[i][1]=max(mp[i-1][1],p[i][1]);
        mp[i][2]=max(mp[i-1][2],p[i][2]);
    }
    s=0;
    for(i=n;i>=1;i--)
    {
       s+=v[i];
       q[i][1]=s-(c-x[i]);
       q[i][2]=s-(c-x[i])*2ll;
       mq[i][1]=max(mq[i+1][1],q[i][1]);
       mq[i][2]=max(mq[i+1][2],q[i][2]);
    }
    
    long long ans=0;
    
    for(i=0;i<=n;i++)
    {
        //cout<<mp[i][1]<<' '<<mp[i][2]<<"   "<<mq[i][1]<<' '<<mq[i][2]<<endl;
        
        ans=max(ans,mp[i][1]+mq[i+1][2]);
        ans=max(ans,mp[i][2]+mq[i+1][1]);
    }
    
    cout<<ans<<endl;
    
    return 0;
}

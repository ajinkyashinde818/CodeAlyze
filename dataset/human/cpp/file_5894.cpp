#include <bits/stdc++.h>
using namespace std;

long long n,x[100005],x1[100005],c,v[100005],v1[100005],dpr[100005],dpr1[100005],fr[100005],fr1[100005],gr[100005],gr1[100005],rez;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>c;
    for(long long i=1;i<=n;i++)
    {
        cin>>x[i]>>v[i];
        dpr[i]=dpr[i-1]+v[i];
        fr[i]=dpr[i]-x[i];
    }
    for(int i=1;i<=n;i++)
        gr[i]=max(gr[i-1],fr[i]);

    for(int i=0;i<=n;i++)
    {
        if(i==0)
            rez=max(rez,gr[n]);
        else
            rez=max(rez,(dpr[n]-dpr[n-i])-(c-x[n-i+1])+gr[n-i]-(c-x[n-i+1]));
    }//////////////////////////
    for(long long i=1;i<=n;i++)
    {
        x1[i]=c-x[n-i+1];
        v1[i]=v[n-i+1];
        dpr1[i]=dpr1[i-1]+v1[i];
        fr1[i]=dpr1[i]-x1[i];
    }
    for(int i=1;i<=n;i++)
        gr1[i]=max(gr1[i-1],fr1[i]);

    for(int i=0;i<=n;i++)
    {
        if(i==0)
            rez=max(rez,gr1[n]);
        else
            rez=max(rez,(dpr1[n]-dpr1[n-i])-(c-x1[n-i+1])+gr1[n-i]-(c-x1[n-i+1]));
    }

    cout<<rez<<endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n,m,d;
int a[300][300];
long long ans=0;

inline int qr()
{
    int s=0,f=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
    return s*f;
}

int main()
{
    n=qr();
    m=qr();
    if(n>=10)
        cout<<m<<endl;
    else
    {
            cout<<m+100*(10-n)<<endl;
    }
    
    return 0;
}

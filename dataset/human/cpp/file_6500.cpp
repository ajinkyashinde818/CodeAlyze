#include<cstdio>

#include<iostream>

using namespace std;

const int N=2e5+5,mod=1e9+7;

typedef long long ll;

int n,f[N];

char s[N];

int main()

{

    scanf("%d",&n);

    scanf("%s",s+1);

    for(int i=2;i<=2*n;i++)

    {

       if(s[i]==s[i-1])

            f[i]=f[i-1]^1;

       else f[i]=f[i-1];

    }

    bool flag=true;

    ll ans=1;

    int t=0;

    for(int i=1;i<=2*n;i++)

    {

        if(f[i]==0)

            t++;

        else 

        {

            if(!t) flag=false;

            ans=ans*t%mod;t--;

        }

        if(t==1&&f[i]==0&&s[i]=='W')

            flag=false;

    }

    if(t) flag=false;

    for(int i=1;i<=n;i++)

        ans=ans*i%mod;

    if(!flag) ans=0;

    printf("%lld",ans);

}

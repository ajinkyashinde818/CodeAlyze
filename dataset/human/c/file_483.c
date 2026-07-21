#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>

#define maxn 200010
typedef long long ll;
int a[maxn];
ll f[maxn];
 
int open()
{
    freopen("datain.txt","r",stdin);
    freopen("dataout.txt","w",stdout);
}
int main(void)
{
    //open();
    ll mi,s;
    int i,n;
    scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0,s=0;i<n;i++)
        {
            s+=a[i];
            f[i+1]=s;
        }
        for(i=2,mi=labs(s-2*f[1]);i<n;i++)
            if(mi>labs(s-2*f[i])) mi=labs(s-2*f[i]);
        printf("%I64d\n",mi);

    return 0;
}

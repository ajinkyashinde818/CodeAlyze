#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll pa[maxn],na[maxn],pb[maxn],nb[maxn];
ll n,c;
ll p1[maxn],n1[maxn];
ll p2[maxn],n2[maxn];
inline void init()
{
    memset(pa, 0, sizeof(pa));memset(na, 0, sizeof(na));
    memset(pb, 0, sizeof(pb));memset(nb, 0, sizeof(nb));
    memset(p1, 0, sizeof(p1));memset(n1, 0, sizeof(n1));
    memset(p2, 0, sizeof(p2));memset(n2, 0, sizeof(n2));
}
int main()
{
    while (scanf("%lld%lld",&n,&c)!=EOF) {
        init();
        for(int i=1;i<=n;i++)scanf("%lld%lld",&pa[i],&pb[i]),na[n-i+1]=c-pa[i];
        for(int i=1;i<=n;i++)nb[i]+=nb[i-1]+pb[n-i+1];
        for(int i=1;i<=n;i++)pb[i]+=pb[i-1];
        //for(int i=1;i<=n;i++)cout<<pa[i]<<" "<<na[i]<<endl;
        for(int i=1;i<=n;i++)
        {
            p1[i]=pb[i]-pa[i];
            p2[i]=pb[i]-pa[i]*2;
        }
        for(int i=1;i<=n;i++)p1[i]=max(p1[i],p1[i-1]),p2[i]=max(p2[i],p2[i-1]);
        for(int i=1;i<=n;i++)
        {
            n1[i]=nb[i]-na[i];
            n2[i]=nb[i]-na[i]*2;
        }
        for(int i=1;i<=n;i++)n1[i]=max(n1[i],n1[i-1]),n2[i]=max(n2[i],n2[i-1]);
        ll mm=0;
        for(int i=1;i<=n;i++)
        {
            mm=max(mm,n1[i]+p2[n-i]);mm=max(mm,n1[i]);mm=max(mm,p1[i]);mm=max(mm,n2[i]+p1[n-i]);
        }
        printf("%lld\n",mm);
    }
    return 0;
}

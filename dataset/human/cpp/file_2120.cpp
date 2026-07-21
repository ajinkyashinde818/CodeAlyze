#include "bits/stdc++.h"
using namespace std;
const int maxn=1e5+100;
typedef long long LL;
LL a[maxn];
int n;
int main()
{
    scanf("%d",&n);
    int tot=0;
    LL sum=0;
    LL mi=INT64_MAX;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]<0) tot++;
        sum+=abs(a[i]);
        mi=min(mi,abs(a[i]));
    }
    if(tot&1) sum-=2*mi;
    printf("%lld\n",sum);
    return 0;
}

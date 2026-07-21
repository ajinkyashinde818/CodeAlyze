#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+7;
int n,k;
ll ans;
int tot;
int x;
int sum;
bool vis[maxn];
int main()
{

    scanf("%d",&n);
    sum=inf;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x<0) tot++;
        sum=min(sum,abs(x));
        ans+=abs(x);
    }
    if(tot%2==0)
        printf("%lld\n",ans);
    else
        printf("%lld\n",ans-sum-sum);
}

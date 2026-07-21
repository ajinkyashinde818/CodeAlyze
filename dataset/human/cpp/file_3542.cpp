#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=100005;
int n,a[max_n];
int main()
{
    scanf("%d",&n);
    bool zero=false;
    ll sum=0;
    int c=0;
    int mv=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        sum+=abs(a[i]);
        mv=min(mv,abs(a[i]));
        if(a[i]<0)c++;
        if(a[i]==0)zero=true;
    }
    if(!zero&&c%2==1)sum-=mv*2;
    printf("%lld\n",sum);
    return 0;
}

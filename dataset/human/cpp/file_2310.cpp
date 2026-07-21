#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+9;
int n;
long long a[sz],sum;
long long mn=1e10;
int cnt;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(a[i]<0){
            sum-=a[i];
            cnt++;
        }
        else sum+=a[i];
        mn=min(abs(a[i]),mn);
    }
    if(cnt&1) sum-=2*mn;
    printf("%lld",sum);
    return 0;
}

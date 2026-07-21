#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100000+10;
const LL INF = 1e16;

int n; 
LL c, x[N], v[N];
LL w[N], preMax[N];

LL solve() {
    preMax[0] = -INF;
    for(int i=1;i<=n;i++) {
        w[i]=v[i]-(x[i]-x[i-1]);
        w[i]=w[i-1]+w[i];
        preMax[i]=max(preMax[i-1],w[i]);
    }
    LL ret = -INF;
    ret = preMax[n];

    LL sum = 0;
    for(int i=n;i>=1;i--) {
        sum += v[i];
        ret=max(ret, sum-2*(c-x[i])+preMax[i-1]);
    }
    return ret;
}
int main() {
    scanf("%d %lld",&n,&c);
    for(int i=1;i<=n;i++) 
        scanf("%lld %lld", &x[i], &v[i]);
    LL ans = max(solve(),0LL);

    for(int i=1;i<=n;i++)
        if(i<n+1-i) {
            swap(x[i],x[n+1-i]);
            swap(v[i],v[n+1-i]);
        }
    for(int i=1;i<=n;i++)
        x[i]=c-x[i];
    ans = max(ans,solve());
    cout<<ans<<endl;
}

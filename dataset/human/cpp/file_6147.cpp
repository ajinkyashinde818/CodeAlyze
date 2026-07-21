#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 101010;
int n;
LL a[MAXN], C, b[MAXN];
LL rema[MAXN], remb[MAXN];

int main(){
    scanf("%d%lld", &n, &C);
    for(int i = 1; i <= n; i ++)
        scanf("%lld%lld", &a[i], &b[i]);
    a[n+1] = C;
    LL ans = 0, rec = 0;
    for(int i = 1; i <= n; i ++){
        rec = rec + b[i] - (a[i] - a[i-1]);
        ans = max(rec, ans);
        rema[i] = max(rema[i-1], rec);
    }
    rec = 0;
    for(int i = n; i > 0; i --){
        rec = rec + b[i] - (a[i+1] - a[i]);
        ans = max(ans, rec);
        remb[i] = max(remb[i+1], rec);
    }
    rec = 0;
    for(int i = 1; i <= n; i ++){
        rec = rec + b[i] - (a[i] - a[i-1]);
        ans = max(ans, rec+remb[i+1]-a[i]);
    }
    rec = 0;
    for(int i = n; i > 0; i --){
        rec = rec + b[i] - (a[i+1] - a[i]);
        ans = max(ans, rec+rema[i-1]-(C-a[i]));
    }
    printf("%lld", ans);
}

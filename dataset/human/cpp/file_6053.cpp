#include <bits/stdc++.h>
using namespace std;
long long su[100005][2];
long long l1[100005];
long long l2[100005];
long long r1[100005];
long long r2[100005];
int main(){
    int n;
    long long m;
    scanf("%d%lld",&n,&m);
    long long ans = 0, mx = 0;
    su[0][0] = 0; su[n+1][0] = m;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&su[i][0], &su[i][1]);
        ans += su[i][1];
    }
    ans -= m; ans += max(su[1][0], m - su[n][0]);
    if(ans < 0) ans = 0;
    long long now1, now2;
    l1[0] = l2[0] = 0;
    now1 = now2 = 0;
    for(int i=1;i<=n;i++){
        now1 += su[i][1];
        now2 += su[i][1];
        now1 -= su[i][0] - su[i-1][0];
        now2 -= su[i][0] - su[i-1][0];
        now2 -= su[i][0] - su[i-1][0];
        l1[i] = max(l1[i-1], now1);
        l2[i] = max(l2[i-1], now2);
    }
    r1[n+1] = r2[n+1] = 0;
    now1 = now2 = 0;
    for(int i=n;i>=1;i--){
        now1 += su[i][1];
        now2 += su[i][1];
        now1 += su[i][0] - su[i+1][0];
        now2 += su[i][0] - su[i+1][0];
        now2 += su[i][0] - su[i+1][0];
        r1[i] = max(r1[i+1], now1);
        r2[i] = max(r2[i+1], now2);
    }
    for(int i=0;i<=n;i++){
        ans = max(ans, max(l1[i] + r2[i+1], l2[i] + r1[i+1]));
    }
    printf("%lld\n", ans);
}

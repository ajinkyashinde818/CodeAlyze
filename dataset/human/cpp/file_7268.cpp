#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, A[200005];
int main(){
    scanf("%d", &N);
    ll ss = 0;
    for(int i = 1; i <= N; i++){
        scanf("%d", A + i);
        ss += 1LL * A[i];
    }
    ll s = 0;
    ll ans = 1e18;
    for(int i = 1; i < N; i++){
        s += A[i];
        ll s2 = ss - s;
        ans = min(ans, abs(s2 - s));
    }
    printf("%lld\n", ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n, a, m = 1e9+7;
long long ans;
bool odd;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        odd ^= a <= 0;
        ans += abs(a);
        m = min(m, abs(a));
    }
    if(odd) ans -= m*2;
    printf("%lld\n", ans);
}

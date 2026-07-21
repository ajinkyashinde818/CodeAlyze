#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll Num[200005];
ll Sum[200005];

int main(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &Num[i]);
        Sum[i] = Sum[i - 1] + Num[i];
    }
    ll Min = 1e15;
    for(int i = 1; i < n; i++){
        ll a = Sum[i];
        ll b = Sum[n] - Sum[i];
        a -= b;
        if(a < 0) a = -a;
        Min = min(Min, a);
    }
    printf("%lld",Min);
    return 0;


}

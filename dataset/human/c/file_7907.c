#include<stdio.h>
#define ll long long
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a / gcd(a,b) * b;}
int main(){
    ll m, n, i, l = 1;
    scanf("%lld%lld",&n,&m);
    ll a[n];
    for(i = 0; i < n; i++){
        scanf("%lld",&a[i]);
        a[i] /= 2;
        l = lcm(l, a[i]);
    }
    for(i = 0; i < n; i++)
        if(l / a[i] % 2 == 0){
            printf("0\n");
            return 0;
        }
    printf("%lld\n",(m / l + 1) / 2);
    return 0;
}

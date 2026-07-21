#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MOD 1000000007
#define MAX 1000001

long long int fac[MAX], finv[MAX], inv[MAX];

void init(){
    fac[0] = 1;
    fac[1] = 1;
    finv[0] = 1;
    finv[1] = 1;
    inv[1] = 1;
    for(int i=2; i<MAX; i++){
        fac[i] = fac[i-1]*i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

long long int combination(long long int n,long long int r){
    if(r<0||n<0){
        return 0;
    }
    if(n < r){
        return 0;
    }
    return (fac[n] * (finv[r] * finv[n-r] % MOD)) % MOD;
}
int main(){
    long long int x, y;
    scanf("%lld%lld", &x, &y);
    long long int ans = 0;
    init();
    if((x+y)%3 == 0){
        int a=x, b=0;
        while(2*a + b != y){
            a -= 2;
            b += 1;
        }
        ans = combination(a+b, a);
    }
    printf("%lld\n", ans);

    return 0;
}

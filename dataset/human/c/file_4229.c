#include<stdio.h>


#define MOD 1000000007
#define MAX 100001
long long int fac[MAX], finv[MAX], inv[MAX];
void MOD_COM_init(){
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
long long int MOD_combination(long long int n,long long int r){
    if(r<0||n<0){
        return 0;
    }
    if(n < r){
        return 0;
    }
    return (fac[n] * (finv[r] * finv[n-r] % MOD)) % MOD;
}

int main(){
    long long int n, m;
    scanf("%lld%lld", &n, &m);
    long long int a[m+2];
    a[0] = -1;
    a[m+1] = n+1;
    for(long long int i=1; i<=m; i++){
        scanf("%lld", &a[i]);
    }
    long long int ans = 1;
    MOD_COM_init();
    for(long long int i=1; i<=m+1; i++){
        //printf("%lld\n", ans);
        long long int w = (a[i]-1) - (a[i-1]+1);
        long long int buf = 0;
        for(long long int j=0; j<=w; j++){
            buf += MOD_combination(w, j);
            buf = buf % MOD;
            w--;
            //printf("  %lld\n", ans);
        }
        ans *= buf;
        ans = ans % MOD;
    }
    printf("%lld", ans);

    return 0;
}

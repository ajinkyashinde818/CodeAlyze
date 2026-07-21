#include <stdio.h>
#include <stdlib.h>
#define ABS(x) ((x < 0) ? -x : x)
#define LL long long

void solve(LL *a, int n){
    int i;
    LL min = 1e15, dif, dif_abs, sum;
    //printf("%lld\n", min);
    sum = 0;
    for(i = 0; i < n; ++i) { sum += a[i]; }
    dif = -sum;
    for(i = 0; i < n-1; ++i) {
        dif += 2*a[i];
        dif_abs = ABS(dif);
        //printf("%lld ", dif_abs);
        if(dif_abs < min) { min = dif_abs; }
    }
    //printf("\n");
    printf("%lld\n", min);
}

int main(void) {
    int n, i;
    scanf("%d", &n);
    LL *a = (LL*)malloc((n+4)*sizeof(LL));
    for(i = 0; i < n; ++i) { scanf("%lld", &a[i]); }
    solve(a,n);
    return 0;
}

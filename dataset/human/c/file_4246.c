#include <stdio.h>
#define mod 1000000007

int main(void){
    int n, m, tmp, i, ans;
    scanf("%d %d", &n, &m);
    int a[n+1];
    for(i = 0; i <= n; ++i){
        a[i] = -1;
    }
    for(i = 0; i < m; ++i){
        scanf("%d", &tmp);
        a[tmp] = 0;
    }
    a[0] = 1;
    if(a[1] < 0){a[1] = 1;}
    for(i = 2; i <= n; ++i){
        if(a[i] < 0){
            a[i] = (a[i-1] + a[i-2]) % mod;
        }
    }

    printf("%d\n", a[n]);
    return 0;
}

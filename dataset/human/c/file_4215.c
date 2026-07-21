#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    const long long int MOD = 1000000007;
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n+1];
    int tmp;
    for (int i = 0;i < n+1;i++){
        a[i] = 0;
    }
    for (int i = 0; i < m;i++){
        tmp = 0;
        scanf("%d",&tmp);
        a[tmp] = 1;
    }

    // 動的計画法？　加算の仕方はフィボナッチ数列みたいな考え方
    long long int total[n+2];
    total[0] = 1;
    // 床が抜けているところは０で埋める
    if (a[1] != 1) total[1] = 1;
    else total[1] = 0;

    for (int i = 2;i < n+1;i++){
        if (a[i] != 1){
            total[i] = (total[i-1] + total[i-2]) % MOD;
        }
        else total[i] = 0;
        // printf("%lld %d\n",total[i],i);
    }
    printf("%lld \n",total[n]);
}

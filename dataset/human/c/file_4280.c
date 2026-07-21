#include <stdio.h>

int main(void){
    int mod = 1000000007;
    int N, M;
    scanf("%d%d", &N, &M);
    long fib[N+1]; //fib[i] は i+1段の段数がある時の上りの数
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i < N+1; i++){
        fib[i] = (fib[i-2] + fib[i-1]) % mod;
    }
    
    int a[M+1];
    a[0] = -1;
    long ans = 1;
    for (int i = 1; i < M+1; i++){
        scanf("%d", &a[i]);
        if(a[i] - a[i-1] == 1){
            printf("%d\n", 0);
            return 0;
        }
    }
    for (int i = 1; i < M+1; i++){
        ans *= fib[(a[i] - a[i-1]) - 2];
        ans = ans%mod;
    }
    ans *= fib[N-a[M]-1];
    ans = ans%mod;
    printf("%ld\n", ans);
    return 0; 
}

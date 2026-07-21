#include <stdio.h>

int main(){
    long long int N;

    scanf("%lld", &N);
    
    if(N % 2 == 1){
        printf("0\n");

        return 0;
    }
    N /= 2;

    long long int ans = 0;

    for(long long int five = 5; five <= N; five *= 5){
        ans += N / five;
    }
    printf("%lld\n", ans);
}

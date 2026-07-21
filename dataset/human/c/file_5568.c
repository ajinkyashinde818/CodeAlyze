#include<stdio.h>

int main(){
    int n, i, j, prime[200000], count;
    long long int sum;

    prime[0] = prime[1] = 1;
    for(i = 2; i < 200000; i++){
        if(prime[i] != 1){
            for(j = 2 * i; j < 200000; j += i) prime[j] = 1;
        }
    }

    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        count = sum = 0;

        for(i = 0; i < 200000; i++){
            if(prime[i] != 1){
                count++;
                sum += i;
                if(count == n) break;
            }
        }

        printf("%lld\n", sum);
    }
    return 0;
};

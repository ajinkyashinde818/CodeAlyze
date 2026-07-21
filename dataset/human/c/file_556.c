#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    int N;

    scanf("%d", &N);

    long long a[N];

    long long sum = 0;

    for(int i = 0; i < N; i++){
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    long long x = 0, y;
    long long min = 100000000000000000;

    for(int i = 0; i < N-1; i++){
        x += a[i];
        y = sum - x;
        if(llabs(x-y) < min){
            min = llabs(x-y);
        }
    }

    printf("%lld\n", min);

    return 0;
}

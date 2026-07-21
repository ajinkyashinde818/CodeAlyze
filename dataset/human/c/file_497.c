#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    int i, N;
    long long sum = 0, a = 0, b = 0, min = LLONG_MAX;
    static int list[2*100000];
    scanf("%d", &N);

    for ( i = 0; i < N; i++ ){
        scanf("%d", &list[i]);
        sum += list[i];
    }
    for ( i = 0; i < N-1; i++ ){
        a += list[i];
        b = sum - a;
        if ( min > llabs(a-b) ){
            min = llabs(a-b);
        }
    }
    printf("%lld\n", min);
    return 0;
}

#include <stdio.h>

#define S_MAX 1000000000

int main(void)
{
    int N, K, S;
    int i;
    
    scanf("%d %d %d", &N, &K, &S);

    if ( S < S_MAX ) {
        for ( i = 0; i < N; i++ ) {
            if ( i < K ) {
                printf("%d ", S);
            } else {
                printf("%d ", (S + 1));
            }
        }
    } else {
        for ( i = 0; i < N; i++ ) {
            if ( i < K ) {
                printf("%d ", S);
            } else {
                printf("1 ");
            }
        }
    }

    return 0;
}

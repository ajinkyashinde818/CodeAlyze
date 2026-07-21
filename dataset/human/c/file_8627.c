#include <stdio.h>

int main(int argc, char *argv[])
{
    static int status[100000], list[100000];
    int i, N, n = 1;
    scanf("%d", &N);
    for ( i = 0; i < N; i++ ){
        scanf("%d", &list[i]);
    }
    status[0] = 1;
    for ( i = 1, n = list[n-1]; n != 2; n = list[n-1], i++ ){
        if ( status[n-1] != 0 ){
            printf("-1\n");
            return 0;
        }
        status[n-1] = 1;
    }
    printf("%d\n", i);
    return 0;
}

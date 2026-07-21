#include <stdio.h>

int
main(int argc, char *argv[])
{
    int N, K;
    int h[100000];
    int i;
    int ride=0;

    scanf("%d%d", &N, &K);
    for (i=0; i<N; i++) {
        scanf("%d", h+i);
        if (*(h+i)>=K)
            ride++;
    }
    printf("%d\n", ride);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#ifdef TEST
struct test {
    int ans;
} td[] = {
    {},
};
#endif

void
solver(int k, int n, int *a)
{
    int i;
    int min_l = k;
    int l;

    min_l = a[n - 1] - a[0];
    for(i = 1; i < n; i++) {
        l = a[i - 1] + k - a[i];
        //        printf("%d; %d %d %d\n", i, l, a[i - 1], a[i]);
        if(min_l > l)
            min_l = l;
    }
    printf("%d\n", min_l);
}

int
main(int argc, char *argv[])
{
#ifdef TEST
    int tt;
    for(tt = 0; tt < sizeof(td) / sizeof(struct test); tt++) {
        solver();
        printf("%d\n", td[tt].ans);
    }
#endif
    int K, N;
    int A[1000000];
    int i;

    scanf("%d%d", &K, &N);
    for(i = 0; i < N; i++)
        scanf("%d", A + i);
    solver(K, N, A);
    return 0;
}

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
solver(int n, int r)
{
    if(n < 10) {
        printf("%d\n", r + 100 * (10 - n));
    } else {
        printf("%d\n", r);
    }
}

int
main(int argc, char *argv[])
{
    int N, R;
#ifdef TEST
    int tt;
    for(tt = 0; tt < sizeof(td) / sizeof(struct test); tt++) {
        solver();
        printf("%d\n", td[tt].ans);
    }
#endif
    scanf("%d%d", &N, &R);
    solver(N, R);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int qsort_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(int argc, char *argv[])
{
    int n;
    int a[100000];
    int log[100000][2];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), qsort_int);

    int p = 0;
    int q = n - 1;
    int logNext = 0;
    while (q - p > 1) {
        if (a[p + 1] > 0) {
            const int x = a[p];
            const int y = a[p + 1];
            const int val = x - y;
            p++;
            a[p] = val;

            // logging
            log[logNext][0] = x;
            log[logNext][1] = y;
            logNext++;
        } else {
            const int x = a[q];
            const int y = a[p + 1];
            const int val = x - y;
            p++;
            a[p] = a[p - 1];
            a[q] = val;

            // logging
            log[logNext][0] = x;
            log[logNext][1] = y;
            logNext++;
        }
    }

    int x = a[q];
    int y = a[p];
    int val = x - y;

    log[logNext][0] = x;
    log[logNext][1] = y;
    logNext++;

    printf("%d\n", val);

    for (int i = 0; i < logNext; i++) {
        printf("%d %d\n", log[i][0], log[i][1]);
    }

    return 0;
}

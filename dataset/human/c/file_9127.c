#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int my_sort(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int main(int argc, void **arg)
{
    long long n, k;
    int h[100000];
    int i;

    scanf("%lld %lld", &n, &k);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
    }

    qsort(h, n, sizeof(int), my_sort);

    for (i = 0; i < n; i++)
    {
        if( h[i] < k ) {
            break;
        }
    }
    printf("%d\n", i);

    return 0;
}

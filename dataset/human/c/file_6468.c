#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    long long int *R;
    long long int max, min;

    scanf("%d", &n);

    R = malloc(n * sizeof(long long int));
    for (i = 0; i < n; i++) scanf("%lld", &R[i]);

    min = R[0];
    max = R[1] - R[0];

    for (i = 1; i < n; i++){
        max = max > R[i] - min ? max : R[i] - min;
        min = min < R[i] ? min : R[i];
    }

    printf("%lld\n", max);

    return (0);
}

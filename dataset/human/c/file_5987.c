#include <stdio.h>

int main(void)
{
    int i;

    int n;
    scanf("%d", &n);

    int R[n];
    for (i=0; i<n; i++)
        scanf("%d", &R[i]);

    int min = R[0], diff = R[1] - R[0];
    for (i=1; i<n-1; i++){
        min = (R[i] < min) ? R[i]: min;
        diff = (diff < R[i+1] - min) ? R[i+1] - min: diff;
    }
    printf("%d\n", diff);
    return 0;
}

#include<stdio.h>

int main(void)
{
    int i, max, min;
    int n, R;
    
    scanf("%d", &n);
    scanf("%d", &R); /* R[0] */
    min = R;
    scanf("%d", &R); /* R[1] */
    max = R - min;
    if ( min > R)
        min = R;
    
    for ( i=2; i<n; ++i) {
        scanf("%d", &R); /* R[i] */
        if ( max < R - min)
            max = R - min;
        if ( min > R)
            min = R;
    }
    printf("%d\n", max);
    return 0;
}

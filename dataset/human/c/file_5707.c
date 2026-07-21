#include<stdio.h>
#include<stdlib.h>

int main()
{
    int  n, x, min, max;
    scanf("%d", &n);
    scanf("%d", &x);
    min  = x;
    max = -999999999;

    for (int i = 0; i < n-1; i++){
        scanf("%d", &x);
        max = (x-min > max) ? x-min : max;
        min = (x > min) ? min : x;
    }
    printf("%d\n", max);
    return 0;
}

/*
 * ID: ALDS1_1_D
 * Problem: Maximum profit
 */

#include <stdio.h>

int main(void)
{
    int n, d, min;

    scanf("%d", &n);

    int i;
    scanf("%d", &d);
    min = d;
    scanf("%d", &d);
    int gain = d - min;
    int top_gain = gain;
    min = min < d ? min : d;
    for (i = 2; i < n; i++) {
        scanf("%d", &d);
        gain = d - min;
        //printf("%d - %d = %d\n", d, min, gain);
        top_gain = top_gain > gain ? top_gain : gain;
        min = min < d ? min : d;
    } 
    printf("%d\n", top_gain);

    return 0;
}

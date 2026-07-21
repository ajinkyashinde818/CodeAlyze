/*
        AOJ - ALDS1_1_D
        Date: 20190310
        Author: Mikoron * ♡mikoiwate_351♡
*/

#define N 200001

#include<stdio.h>

int main(void) {
        int i, j, n, max_diff, min;
        int value;

        scanf("%d", &n);
        scanf("%d", &min);
        max_diff = -999999999;
        for(i = 1; i < n; i++) {
                scanf("%d", &value);
                if(max_diff < value - min) max_diff = value - min;
                if(min > value) min = value;
        }

        printf("%d\n", max_diff);

        return 0;
}

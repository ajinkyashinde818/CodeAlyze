#include <stdio.h>

#define MAX(a, b) (a >= b)? a: b;
#define MIN(a, b) (a <= b)? a: b;

int main(void)
{
    int i;

    int data_num;
    scanf("%d", &data_num);

    long rate_min, rate_tmp;
    scanf("%ld %ld", &rate_min, &rate_tmp);
    long range_max = rate_tmp - rate_min;
    rate_min = MIN(rate_min, rate_tmp);

    long range_tmp;
    for (i = 2; i < data_num; i++) {
        scanf("%ld", &rate_tmp);
        range_tmp = rate_tmp - rate_min;
        rate_min = MIN(rate_min, rate_tmp);
        range_max = MAX(range_max, range_tmp);
    }

    printf("%ld\n", range_max);

    return 0;
}

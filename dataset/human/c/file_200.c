#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int
main(void)
{
        int N;
        int minus = 0;
        uint64_t sum = 0;
        int min = INT_MAX;

        scanf("%d\n", &N);
        for (int i = 0; i < N; i++) {
                int a;
                scanf("%d%*c", &a);
                if (a < 0)
                        minus++;
                sum += abs(a);
                if (abs(a) < min)
                        min = abs(a);
        }

        if (minus % 2)
                sum -= min * 2;

        printf("%lu", sum);
}

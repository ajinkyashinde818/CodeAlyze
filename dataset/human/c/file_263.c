#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <memory.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int n;
    int a[100000];
    int i;
    int absmin_pos;
    int absmin = INT_MAX;
    long long sum;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (abs(a[i]) < absmin) {
            absmin = abs(a[i]);
            absmin_pos = i;
        }
    }

    for (i = 0; i < absmin_pos; i++) {
        if (a[i] < 0 && (i < n - 1)) {
            // DO
            a[i    ] *= -1;
            a[i + 1] *= -1; 
        }
    }

    for (i = n - 1; i > absmin_pos; i--) {
        if (a[i] < 0 && (i > 0)) {
            // DO
            a[i - 1] *= -1;
            a[i    ] *= -1; 
        }
    }

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += a[i];
    }
    printf("%lld\n", sum);

    return 0;
}

#include <stdio.h>

int main () {

    int n, min, i, x, s, t;

    scanf("%d", &n);

    min = 1000000001; t = -1000000001;

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        s = x - min;
        if (s >= t && i != 0)
            t = s;
        if (min > x)
            min = x;
    }

    printf("%d\n", t);

    return 0;

}

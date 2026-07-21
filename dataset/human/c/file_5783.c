#include <stdio.h>

int
main()
{
    int n, i, x;
    int maxv, minv;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (i == 0) {
            minv = x;
            continue;
        }

        if (i == 1) {
            maxv = x - minv;
            if (minv > x)
                minv = x;
            continue;
        }

        if (maxv < (x - minv))
            maxv = x - minv;

        if (minv > x)
            minv = x;
    }
    printf("%d\n", maxv);
    return 0;
}

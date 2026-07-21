#include <stdio.h>

int
main(void)
{
        int n;
        int x;
        int maxv;
        int min;

        scanf("%d\n", &n);
        scanf("%d\n", &x);
        scanf("%d\n", &maxv);
        min = (x < maxv) ? x : maxv;
        maxv = maxv - x;

        for (int i = 2; i < n; i++) {
                scanf("%d\n", &x);
                int v = x - min;
                if (x < min)
                        min = x;
                else if (maxv < v)
                        maxv = v;
        }

        printf("%d\n", maxv);

        return 0;
}

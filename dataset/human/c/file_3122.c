#include <stdio.h>

int main()
{
    int i;
    int k, n;
    int first, pre, crnt, dist;
    int max = 0, max_i;

    scanf("%d%d", &k, &n);

    scanf("%d", &first);

    pre = first;

    for (i = 1; i < n; i++) {
        scanf("%d", &crnt);
        dist = crnt - pre;
        if (dist > max) {
            max = dist;
        }
        pre = crnt;
    }

    dist = k - pre + first;
    if (dist > max)  {
        max = dist;
    }

    printf("%d\n", k - max);

    return 0;
}

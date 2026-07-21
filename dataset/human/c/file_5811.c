#include <stdio.h>

int main(void){
    int i, j, n, r[200000], max, rmin;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &r[i]);

    max = r[1] - r[0];
    rmin = r[0];

    for (i = 1; i < n; i++)
    {
        if (max < r[i] - rmin) max = r[i] - rmin;
        if (rmin > r[i]) rmin = r[i];
    }

    printf("%d\n", max);
    return 0;
}

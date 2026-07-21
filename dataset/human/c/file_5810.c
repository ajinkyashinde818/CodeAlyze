#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);

    int min;
    scanf("%d", &min);

    int g = -999999999;

    n--;
    int R, t;

    while (n--) {
        scanf("%d", &R);
        t = R - min;
        if (g < t) g = t;
        if (R < min) min = R;
    }

    printf("%d\n", g);

    return 0;
}

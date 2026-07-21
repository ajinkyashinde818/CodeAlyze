#include <stdio.h>

int main(void)
{
    int a, b, c, d;
    int area1, area2, max;

    scanf("%d %d %d %d", &a, &b, &c, &d);
    area1 = a * b;
    area2 = c * d;
    max = (area1 > area2) ? area1 : area2;
    printf("%d", max);

    return 0;
}

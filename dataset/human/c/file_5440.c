#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a < b ? b : a;
}

int main(void)
{
    int n;
    int sum;
    int x[1024], y[1024];
    int i;

    scanf("%*d %*d %d", &n);
    scanf("%d %d", x, y);
    sum = 0;
    for (i = 1; i < n; ++i){
        int dx, dy;
        scanf("%d %d", x + i, y + i);
        dx = x[i] - x[i - 1];
        dy = y[i] - y[i - 1];
        if (0 <= dx * dy){
            sum += max(abs(dx), abs(dy));
        }
        else {
            sum += abs(dx) + abs(dy);
        }
    }

    printf("%d\n", sum);

    return 0;
}

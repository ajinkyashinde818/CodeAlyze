#include <stdio.h>
#include <math.h>

int main()
{
    int n, d, x, ai;
    scanf("%d", &n);
    scanf("%d %d", &d, &x);
    for(int i = 0; i < n; i++){
        scanf("%d", &ai);
        x += (floor((d-1)/ai) + 1);
    }

    printf("%d", x);
    return 0;
}

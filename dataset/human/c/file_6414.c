#include <stdio.h>
#define INF 1000000000

int main()
{
    int n, i, x = -INF, y = -INF, min = INF;
    int s[200000] = {0};
    
    scanf ("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    
    for (i = 0; i < n - 1; i++) {
        if (s[i] < min) {
            min = s[i];
        }
        x = s[i + 1] - min;
        if (x > y) {
            y = x;
        }
    }
    
    printf ("%d\n", y);
    
    return 0;
}

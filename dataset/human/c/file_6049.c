#include <stdio.h>

int main()
{
    int i, n, r[200000];
    int max = -1000000000, min;
    
    scanf("%d", &n);
    scanf("%d", &r[0]);
    min = r[0];
    for (i = 1; i < n; i++){
        scanf("%d", &r[i]);
        if (max < r[i] - min) max = r[i] - min;
        if (min > r[i]) min = r[i];
    }
    printf("%d\n", max);
    
    return 0;
}

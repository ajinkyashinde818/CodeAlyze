#include <stdio.h>
#include <limits.h>

int
main(void)
{
    int i, n, tmp, max = INT_MIN, min = INT_MAX;
    
    scanf("%d", &n);
    
    for(i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        if(max < tmp - min) max = tmp - min;
        if(min > tmp) min = tmp;
    }
    
    printf("%d\n", max);
}

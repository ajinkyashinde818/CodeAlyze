#include <stdio.h>

int     main(void)
{
    int i, x;
    
    i = 1;
    while (i <= 10000)
    {
        scanf("%d", &x);
        
        if (x == 0)
        {
            break;
        }
        
        printf("Case");
        printf(" ");
        printf("%d:", i);
        printf(" ");
        printf("%d\n", x);
        
        i++;
    }
    return (0);
}

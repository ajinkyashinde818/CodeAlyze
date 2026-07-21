#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, cont = 1;
    scanf("%d", &a);
    printf("Case %d: %d\n", cont, a);
    while(a != 0)
    {
        scanf("%d", &a);
        cont += 1;
        if (a != 0)
        {
            printf("Case %d: %d\n", cont, a);
        }
    }

return 0;
}

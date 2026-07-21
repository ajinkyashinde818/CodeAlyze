#include <stdio.h>
int main()
{
    int n, d1, d2, i, count = 0, mn = 0;
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        scanf("%d %d", &d1, &d2);
        if(d1 == d2)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if(count > mn)
        {
            mn = count;
        }
    }
    if(mn >= 3)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

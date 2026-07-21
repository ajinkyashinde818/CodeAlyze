#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n, i, count=0;
    scanf("%d", &n);
    int x[n+5], y[n+5];

    for(i=1; i<=n; i++)
        scanf("%d%d", &x[i], &y[i]);

    for(i=1; i<=n-2; i++)
    {
        if(x[i]==y[i])
        {
            if(x[i+1]==y[i+1])
            {
                if(x[i+2]==y[i+2])
                {
                    count=1;
                    break;
                }
            }
        }
    }

    if(count==0)
        printf("No\n");
    else
        printf("Yes\n");

    return 0;
}

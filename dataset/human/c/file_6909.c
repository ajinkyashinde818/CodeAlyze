#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    scanf("%d %d",&n,&m);
    while(n>=1&&n<=100&&m>=0&&m<=n)
    {
        if(m==n)
        {
         printf("Yes");
            break;
        }
        else
            {
         printf("No");
            break;
        }
    }
    return 0;
}

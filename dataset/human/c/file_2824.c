#include <stdio.h>

int main()
{
    int k,s,i,j,ans = 0;

    scanf("%d %d",&k,&s);

    for (i = 0; i <= k; i++)
    {
        for (j = 0; j <= k; j++)
        {
          	//printf("%d %d %d\n",i,j,s - i - j);
            if ((0 <= s - i - j) && (s - i - j <= k))
            {
              	//printf("%d %d %d\n",i,j,s - i - j);
                ans ++;
            }
        }
    }

    printf("%d",ans);
}

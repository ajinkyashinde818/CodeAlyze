#include <stdio.h>

int main()
{
    int r,g,b,n,v,ans = 0;
    scanf("%d %d %d %d",&r,&g,&b,&n);

    for (int i = 0; i <= 3000; i++)
    {
        for (int j = 0; j <= 3000; j++)
        {
            v = i * r + j * g;
            if ((n >= v) && (n - v) % b == 0)
            {
                ans ++;
            }
            
        }
        
    }
    
    printf("%d",ans);
}

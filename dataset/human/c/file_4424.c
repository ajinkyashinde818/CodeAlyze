#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void)
{
    int n,d1[101],d2[101],i;
    scanf("%d",&n);
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d %d",&d1[i],&d2[i]);
    }
    for(i = 0 ; i <= n - 3 ; i++)
    {
        if(d1[i] == d2[i] && d1[i + 1] == d2[i + 1] && d1[i + 2] == d2[i + 2])
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}

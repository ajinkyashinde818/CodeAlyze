#include <stdio.h>

int n;
int d[110][2];

int main()
{
    for(int i=0;i<110;i++)
    {
        d[i][0]=-1;
        d[i][0]=-2;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d%d",&d[i][0],&d[i][1]);

    for(int i=0;i<n;i++)
    {
        if(d[i][0]==d[i][1])
        {
            if(d[i+1][0]==d[i+1][1]&&d[i+2][0]==d[i+2][1])
            {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}

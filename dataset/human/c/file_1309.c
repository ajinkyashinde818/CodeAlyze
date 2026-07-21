#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    int m,n;
    while (~scanf("%d%d",&m,&n))
    {
        int a[250000][2]= {0};
        int x,y;
        int flag=0;
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&x);
            scanf("%d",&y);
            if(x==1)
                a[y][1]=1;
            if(y==m)
                a[x][0]=1;
        }
        for(int j=1; j<=n; j++)
            if(a[j][0]&&a[j][1])
                flag=1;
//        printf("%d %d \n",a[2][0],a[2][1]);
        if(flag)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
}

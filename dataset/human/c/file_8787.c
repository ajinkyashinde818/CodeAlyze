#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,w,i,j,flag,flag2;
    char temp;
    int a[50][50];
    scanf("%d%d",&h,&w);
    scanf("%c",&temp);
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            scanf("%c",&temp);
            if(temp=='#')
                a[i][j]=1;
            else a[i][j]=0;
        }
            scanf("%c",&temp);
    }
    flag2=0;
        for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            flag=0;
            if(a[i][j]==0)
                continue;
            if(a[i][j]==1)
            {
                if(a[i+1][j]+a[i][j+1]+a[i-1][j]+a[i][j-1]>=1&&i>0&&i<h-1&&j<w-1&&j>0)
                flag=1;
                else if(a[i][j+1]+a[i-1][j]+a[i][j-1]>=1&&i==h-1)
                flag=1;
                else if(a[i+1][j]+a[i-1][j]+a[i][j-1]>=1&&j==w-1)
                flag=1;
                else if(a[i+1][j]+a[i][j+1]+a[i][j-1]>=1&&i==0)
                flag=1;
                else if(a[i+1][j]+a[i][j+1]+a[i-1][j]>=1&&j==0)
                flag=1;
            }
            if(flag==0)
            {
                flag2=1;
                break;
            }


        }
        if(flag2==1)
            break;
    }
    if(flag2==1) printf("No");
    else printf("Yes");

    return 0;
}

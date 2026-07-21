#include<stdio.h>
#include<string.h>
int main()
{
    char a[10],op;
    int i,j,b[10];
    while(scanf("%s",a)==1)
    {
        op='a',b[0]=0,b[1]=0,b[2]=0;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(a[j]==op)
                {
                    op++;
                    b[j]=1;
                    break;
                }
            }
        }
        for(i=0;i<3;i++)
        {
            if(b[i]==0)
            {
                printf("No\n");
                break;
            }
        }
        if(i==3)
            printf("Yes\n");

    }
    return 0;
}

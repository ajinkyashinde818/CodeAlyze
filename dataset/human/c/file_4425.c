#include<stdio.h>

int main()
{
    int N,i,x,y,count=0,check=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&x,&y);
        if(x==y)
        {
            count++;
            if(count==3)
            {
                check=1;
            }
        }
        else
        {
            count=0;
        }
    }
    if(check==1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}

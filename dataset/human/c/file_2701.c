#include<stdio.h>

int main()
{
    int x,y,s,k;
    int ret=0;

    scanf("%d%d",&k,&s);
    
    for(x=0;x<=k;x++)
    {
        for(y=0;y<=k;y++)
        {
            if(s-x-y<0) break;
            if(s-x-y<=k)
            {
                ret++;
            }
        }
    }

    printf("%d\n",ret);
    return 0;
}

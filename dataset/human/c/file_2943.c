#include <stdio.h>
int main()
{
    int k,s,i,j,x,c=0;
    scanf("%d %d",&k,&s);
    for(i=0; i<=k; i++)
    {
        for(j=0; j<=k; j++)
        {
            x=s-(i+j);
                if(x>=0 && x<=k)
                {
                    c++;
                }
        }
    }
    printf("%d\n",c);
    return 0;
}

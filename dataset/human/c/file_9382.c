#include <stdio.h>
int main()
{
    int n,d,x,i,s[105],j,sum=0;
    scanf("%d %d %d",&n,&d,&x);
    for(i=0;i<n;i++)
        scanf("%d",&s[i]);
    for(i=0;i<n;i++)
    {
        sum=sum+1;
        for(j=1;;j++)
        {
            if(s[i]*j+1<=d)
                sum=sum+1;
            else
                break;
        }
    }
    printf("%d\n",sum+x);
    return 0;
}

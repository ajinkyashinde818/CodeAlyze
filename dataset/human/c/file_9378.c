#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[110],i,n,d,x;
    scanf("%d%d%d",&n,&d,&x);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int total=0;
    for(i=1;i<=n;i++)
    {
          total=total+1;
           int cont=1;
           while(1)
           {
               if(d>=cont*a[i]+1)
                cont++;
               else
                break;
           }
           total=total+cont-1;

    }
    int q;
    q=total+x;
    printf("%d",q);
    return 0;
}

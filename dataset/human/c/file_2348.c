#include <stdio.h>

int main()
{
    long int n,k,s;
    long int i;

    scanf("%ld %ld %ld",&n,&k,&s);

    if(s==1000000000)
    {
        for(i=0;i<k;i++)
    {
        printf("%ld ",s);
    }

    for(i=0;i<n-k;i++)
    {
        printf("%ld ",s-1);
    }
    }
    else
    {    
        for(i=0;i<k;i++)
        {
            printf("%ld ",s);
        }

        for(i=0;i<n-k;i++)
        {
            printf("%ld ",s+1);
        }
    }

    printf("\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int i,j,k;
    long long int n,a[100],b[100],c[100],point=0;
    scanf("%lld",&n);

    for(i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
    }
     for(i=0; i<n; i++)
    {
        scanf("%lld",&b[i]);
    }
     for(i=0; i<n-1; i++)
    {
        scanf("%lld",&c[i]);
    }

    for(i=0; i<n; i++)
    {
        if(i==0)
        {
            
            point+=b[a[i]-1];
            // printf("%lld  ",point);
        }else
        {
            if(a[i]==a[i-1]+1)
            {
                point+=c[a[i-1]-1];
            }
            point+=b[a[i]-1];
        }
    }
    
    printf("%lld",point);
    
    return 0;
}

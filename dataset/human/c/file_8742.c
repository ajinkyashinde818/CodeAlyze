#include <stdio.h>

int main(void)
{
    int n,i,j=1,t;
    int a[100000]={0};
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    i=0;
    while(n>0&&j<100000)
    {
        if(a[i]!=2)
        {
            t = a[i]-1;
            i = t;
            j++;
        }
        else
        {
            n=0;
        }
        
    }
    if(j>=100000)
    {
        j=-1;
    }
    printf("%d\n",j);
    
    return 0;
}

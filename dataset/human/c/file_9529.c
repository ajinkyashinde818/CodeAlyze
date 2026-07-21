#include <stdio.h>
 
int main()
{
    int n,d,x,a,Ans=0,i;
 
    scanf("%d %d %d",&n,&d,&x);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a);
       
        Ans+=(d-1)/a;
       
        Ans++;
       
    }
    printf("%d\n",Ans+x);
 
    return 0;
}

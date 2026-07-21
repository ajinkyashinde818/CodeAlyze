#include <stdio.h>

int main (void)
{
   int n , d , x=0 , i , j;

       scanf("%d",&n);
   int a[n+1];
       scanf("%d%d",&d,&x);
    for(i=0; i<n; i++)
       scanf("%d",&a[i]);

    for(i=0; i<n; i++){
      for(j=1; j<=d; j=j+a[i])
         x = x + 1;
    }

    printf("%d\n",x);
    return 0 ;
}

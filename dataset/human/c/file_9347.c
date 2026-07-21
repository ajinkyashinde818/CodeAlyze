#include <stdio.h>
int main(void)
{
   int n, d, x, i, y=0, e, s=0;
   int a[101];

   scanf("%d%d%d",&n,&d,&x);

   for(i=0;i<n;i++)
      scanf("%d",&a[i]);

   for(i=0;i<n;i++){
        e=0;
        y=0;
      while(y<=d){
        e++;
        y=e*a[i]+1;
      }

      s=s+e;
    }

    printf("\n%d\n",x+s);

    return 0;
    }

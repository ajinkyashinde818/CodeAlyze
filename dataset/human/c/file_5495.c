#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
   int n,i,s,j,c,k,b;
   while(~scanf("%d",&n))
   {
       if(n==0)
        break;
       s=0,i=2,c=0,k=1;
       while(1)
       {
           b=sqrt(i);
           for(j=1;j<=b;j++)
           {
               if(i%j==0&&j!=1)
                     {k++;break;}
           }
            if(k==1)
            {
                s+=i;
                c++;
            }
           k=1;
           if(c==n)
           {
               break;
           }
           i++;
       }
       printf("%d\n",s);

   }

}

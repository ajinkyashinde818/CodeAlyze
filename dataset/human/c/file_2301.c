#include<stdio.h>
#define MAXN 100000
int main ()
{  int n,k,s,i;
   scanf("%d %d %d",&n,&k,&s);
   for(i=1;i<=k;i++)
     {   if(i<=n-1) printf("%d ",s);
         else
         printf("%d",s);
     }
     if(s==1000000000)  s=s-2;
     for(i=k+1;i<=n;i++)
      {  if(i<=n-1) printf("%d ",s+1);
         else
         printf("%d",s+1);
     }
     return 0;
}

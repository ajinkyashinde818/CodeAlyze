#include<stdio.h>
int main(void)
{
   int r[200000],n,minv,j,maxv;
   scanf("%d",&n);
   for(j=0;j<n;j++)
   {
      scanf("%d",&r[j]);
   }
   minv = r[0];
   maxv = -2000000000;
   for(j=1;j<n;j++)
   {
      maxv = (maxv > r[j]-minv) ? maxv : r[j]-minv ;
      minv = (minv < r[j]) ? minv : r[j] ;
   }
   printf("%d\n",maxv);
}

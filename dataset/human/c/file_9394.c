#include<stdio.h>

int main(void)
{
   int d,n,x,a[100],b[100],i, sum=0;
   scanf("%d",&n);
   scanf("%d %d",&d,&x);
   for(i=0;i<n;i++){
      scanf("%d",&a[i]);
      b[i]=a[i];
   }
   for(i=0;i<n;i++){
      sum++;
      while(a[i]+1<=d){
         sum++;
         a[i]+=b[i];
      }
   }
   sum+=x;
   printf("%d\n",sum);
   return 0;
}

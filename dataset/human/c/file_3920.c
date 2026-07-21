#include<stdio.h>

int main(void)
{
   int a, b, k, i, x=0, z=1;

   scanf("%d%d%d",&a,&b,&k);

   if(a>b){
      i=a;
      a=b;
      b=i;
   }

   i=a;
   while(x==0){
      if((a%i==0)&&(b%i==0)){
         if(z!=k)
            z++;
         else
            x=i;
      }
      i--;
   }

   printf("%d\n",x);
   return 0;
}

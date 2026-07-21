#include<stdio.h>
int main()
{
     unsigned long long t,a,b,i;
    scanf("%llu%llu",&a,&b);
     t=a*b;
    if(a<b)
     {
         i=a;a=b;b=i;
     }
   while(b!=0)
   {
       i=a%b;
       a=b;
       b=i;

   }
   printf("%llu",t/a);
    return 0;
}

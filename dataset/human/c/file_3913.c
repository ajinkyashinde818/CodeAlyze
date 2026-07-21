#include<stdio.h>

int main(void)
{
 int a,b,k,i,n[100],j=0;
 scanf("%d%d%d",&a,&b,&k);
 for(i=a;i>0;i--)
 {
   if( (a%i)==0 && (b%i)==0 )
   {
     n[j] = i;
     j++;
   }
 }
 printf("%d\n",n[k-1]);
 return 0;
}

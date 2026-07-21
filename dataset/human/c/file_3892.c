#include<stdio.h>
int main(void)
{
   int a,b,k,j,w,n=0,m=1;
   scanf("%d%d%d",&a,&b,&k);
   if(a<b) w=a;
   else w=b;
   for(j=w;n<k;j--){
      if((a%j==0)&&(b%j==0)){
         n++;
      }
   }
   printf("%d\n",j+1);
   return 0;
}

#include <stdio.h>

int main(){
   int a,b,k,i;
    
   scanf("%d %d %d",&a,&b,&k);
   if (a>b) i=b;
   else     i=a;
   for (;k>0;k--,i--)
      while (a%i!=0 || b%i!=0) i--;
   printf("%d\n",i+1);
   return 0;
}

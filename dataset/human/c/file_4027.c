#include<stdio.h>

int main(void)
{
   int a, b, c, i, g, d[100];

   scanf("%d %d %d", &a, &b, &c);
   g=0;
   for(i=a;i>=1;i--){
        if((a%i==0)&&(b%i==0)){
                d[g]=i;
                g=g+1;
 
        }
   }

   printf("%d\n",d[c-1]);
   return 0;
}

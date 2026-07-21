#include<stdio.h>

int main(void)
{
   int n, d, x, i, j;
   int a[100];

   scanf("%d%d%d", &n, &d, &x);
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);

   for(i=0;i<n;i++)
      for(j=1;j<=d;j++){
         if((j == 1)||((j-1) % a[i] == 0)){
            x = x + 1;}
}
   printf("%d\n", x);
   return 0;
}

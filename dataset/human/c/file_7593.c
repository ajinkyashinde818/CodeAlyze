#include<stdio.h>

int main(void)
{
   int n, x[100000], i;
   x[0] = 1;
   n = 1;
   while(x[n-1] != 0){
      scanf("%d", &x[n]);
      n++;
   }

   for(i = 1; i < n-1; i++){
      printf("Case %d: %d\n", i, x[i]);
   }
   return 0;
}

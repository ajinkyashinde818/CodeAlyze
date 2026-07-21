#include <stdio.h>
int main (void)
{
   int i,j,x[10000];
   i = 0;
   do{
      scanf("%d",&x[i]);
      i++;
   }while(x[i-1] != 0);
   for(j=1;j<i;j++){
      printf("Case %d: %d\n",j,x[j-1]);
   }
   return 0;
}

#include <stdio.h>

int main(){
   int  i,j,k,n,d1,d2;

   scanf("%d",&n);
   for (k=j=i=0;i<n;i++) {
      scanf("%d %d",&d1,&d2);
      if (d1==d2) {
         j++;
         if (j>=3) k++;
      } else
         j=0;
   }
   if (k>0) puts("Yes");
   else     puts("No");
   return 0;
}

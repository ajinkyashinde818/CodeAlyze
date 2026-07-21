#include <stdio.h>

int main(){
   int i, n, R, Rmin, diff_max;
   scanf("%d",&n);
   for(i=0;i<n;i++){
      scanf("%d",&R);
      if(i==1||R-Rmin>diff_max) diff_max=R-Rmin;
      if(i==0||R<Rmin) Rmin=R;
   }
   printf("%d\n",diff_max);
   return 0;
}

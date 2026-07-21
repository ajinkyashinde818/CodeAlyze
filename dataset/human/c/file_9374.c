#include<stdio.h>

int main()
{
   int n, d, x, i, j, asum, nd;                                                                                                             
   nd = j = 1;
   asum = 0;
   int a[100],count[100];

   scanf("%d",&n);
   scanf("%d %d",&d, &x);


   for(i=0;i<n;i++){
      scanf("%d",&a[i]);
   }

   for(i=0;i<n;i++){
      count[i] = 0;
      while(nd <= d){
         count[i]++;
         nd = j * a[i] + 1;
         j++;
      }
      nd = j = 1;
   }


   for(i=0;i<n;i++){
      asum += count[i];
   }

   printf("\n%d\n",asum + x);

   return 0;
}

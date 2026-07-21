#include <stdio.h>

int main(){
   int n,i,j,a[200000],b[200000];
   long long k;

   scanf("%d %lld",&n,&k);
   for (i=0;i<n;i++) {
      scanf("%d",&a[i]);
      a[i]--;
      b[i]=-1;
   }
   for (i=j=0;k>0;j++,k--)
      if (b[i]>=0) {
         k=k%(j-b[i]);
         for (;k>0;k--) i=a[i];
         printf("%d\n",i+1);
         return 0;
      } else {
        b[i]=j;
        i=a[i];
      }
   printf("%d\n",i+1);
   return 0;
}

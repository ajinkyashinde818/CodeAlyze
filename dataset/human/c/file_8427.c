#include <stdio.h>

int main(){
   int n,k,i,j,K;
   long a[1000],aa[1000*1000],m,mm,ko;
    
   scanf("%d %d",&n,&K);
   for (i=0;i<n;i++) 
      scanf("%ld",&a[i]);
   k=0;
   for (i=0;i<n;i++)
      for (j=i;j<n;j++) {
         if (j==i) aa[k]=a[j];
         else      aa[k]=aa[k-1]+a[j];
         if (aa[k]>m) m=aa[k];
         k++;
      }
   for (mm=1;m>1;mm*=2) m/=2;
   for (ko=0;mm>0;mm/=2) {
      for (i=j=0;i<k;i++) 
         if ((aa[i]&mm)==mm) j++;
      if (j>=K) {
         ko+=mm;
         for (i=j=0;i<k;i++)
            if ((aa[i]&mm)==mm) aa[j++]=aa[i];
         k=j;
      }
   }
   printf("%ld\n",ko);
   return 0;
}

#include <stdio.h>

int main(){
   int n,i,j,k,a[20],b[20],c[20],s;
 
   scanf("%d",&n);
   for (i=0;i<n;i++) scanf("%d",&a[i]);
   for (i=0;i<n;i++) scanf("%d",&b[i]);
   for (i=0;i<n-1;i++) scanf("%d",&c[i]);
   k=-9;
   for (s=i=0;i<n;i++) {
      j=a[i]-1;
      s+=b[j];
      if (j==k+1) s+=c[k];
      k=j;
   }
   printf("%d",s);
   return 0;
}

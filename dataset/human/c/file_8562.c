#include <stdio.h>
#include <stdlib.h>

int asc(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main(){
   int n,i,a[100000],m;
    
   scanf("%d",&n);
   for (i=0;i<n;i++) scanf("%d",&a[i]);
   qsort(a,n,sizeof(int),asc);
   m=a[n-1]-a[0];
   for (i=1;i<n-1;i++)
      if (a[i]>0) m+=a[i];
      else        m-=a[i];
   printf("%d\n",m);
   for (i=1;i<n-1;i++)
      if (a[i]>0) {
         printf("%d %d\n",a[0],a[i]);
         a[0]-=a[i];
      } else {
         printf("%d %d\n",a[n-1],a[i]);
         a[n-1]-=a[i];
      }
   printf("%d %d\n",a[n-1],a[0]);
   return 0;
}

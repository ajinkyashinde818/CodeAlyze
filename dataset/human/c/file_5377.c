#include <stdio.h>

int main(){
   int n,m,x,i,j,c[12],a[12][12],u[13],min,s[12],cs,mino;

   scanf("%d %d %d",&n,&m,&x);
   min=1;
   for (i=0;i<n;i++) {
      scanf("%d",&c[i]);
      min+=c[i];
      u[i]=0;
      for (j=0;j<m;j++) scanf("%d",&a[i][j]);
   }
   mino=min;
   u[n]=0;
   for (;;) {
      for (i=0;i<n;i++)
         if (u[i]==0) {
            u[i]=1;
            break;
         } else u[i]=0;
      if (i==n) break;
      for (i=0;i<m;i++) s[i]=0;
      cs=0;
      for (i=0;i<n;i++)
         if (u[i]) {
            for (j=0;j<m;j++) s[j]+=a[i][j];
            cs+=c[i];
         }
      for (i=0;i<m;i++)
         if (s[i]<x) break;
      if (i==m && cs<min) min=cs;
   }
   if (min<mino) printf("%d\n",min);
   else          puts("-1");
   return 0;
}

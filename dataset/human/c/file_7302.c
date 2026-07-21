#include <stdio.h>

int main(){
   int h,w,k,i,j,a[300][300],c,f,ff;
   char s[300][301];
 
   scanf("%d %d %d",&h,&w,&k);
   for (i=0;i<h;i++) {
      scanf("%s",&s[i]);
      for (j=0;j<w;j++)
         if (s[i][j]=='.') a[i][j]=0;
         else              a[i][j]=k--;
   }
   for (ff=i=0;i<h;i++) {
      for (f=c=j=0;j<w;j++)
         if (a[i][j]==0 && c>0) a[i][j]=c;
         else if (a[i][j]>0) c=a[i][j];
         else f=1;
         if (f && c>0) {
            for (j=0;a[i][j]==0;j++) ;
            c=a[i][j];
            for (j--;j>=0;j--) a[i][j]=c;
         } else if (f && ff) {
            for (j=0;j<w;j++) a[i][j]=a[i-1][j];
         }
         if (c>0 && ff==0) {
            ff=1;
            for (k=0;k<i;k++)
               for (j=0;j<w;j++) a[k][j]=a[i][j];
         }
   }     
   for (i=0;i<h;i++) {
      printf("%d",a[i][0]);
      for (j=1;j<w;j++)
         printf(" %d",a[i][j]);
      puts("");
   }
   return 0;
}

#include <stdio.h>
int main(void){
   int n,a[21],b[21],c[21],sum=0,add=-1;
   
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
       scanf("%d",&a[i]);
   }
    for(int i=1;i<=n;i++){
       scanf("%d",&b[i]);
   }
    for(int i=1;i<n;i++){
       scanf("%d",&c[i]);
   }
   
   for(int i=1;i<=n;i++){
       sum += b[a[i]];
       if(add==a[i]-1){sum+=c[a[i-1]];}
       add = a[i];
   }
   printf("%d",sum);
   return 0;
}

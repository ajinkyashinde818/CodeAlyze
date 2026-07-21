#include <stdio.h>
#include <string.h>
#include <math.h>
 int main(void){
    
    int N,i,s=0;
   scanf("%d",&N);
    int a[N],b[N],c[N-1];
   for(i=0;i<N;i++)
     scanf("%d",&a[i]);
   for(i=0;i<N;i++)
     scanf("%d",&b[i]);
   for(i=0;i<N-1;i++)
     scanf("%d",&c[i]);
   for(i=0;i<N;i++){
     s+=b[a[i]-1];
     if(i>0){
       if(a[i]-a[i-1]==1){
         s+=c[a[i-1]-1];
       }
     }
   }
   printf("%d",s);     
}

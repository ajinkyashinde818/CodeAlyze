#include <stdio.h>
int main(){
   int n,k;
   scanf("%d%d",&n,&k);
   int h[n];
   for(int a=0;a<n;a++){
       scanf("%d",&h[a]);
   } 
   int count=0;
   for(int b=0;b<n;b++){
       if(h[b]>=k){count++;}
       else{}
   }
   printf("%d\n",count);
   return 0;
}

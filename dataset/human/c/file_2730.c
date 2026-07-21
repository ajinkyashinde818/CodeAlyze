#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a > b) ? a : b
#define MIN(a,b) (a < b) ? a : b
const int inf = 1000000000; // 10^9

int main(){
   int k,s;scanf("%d %d",&k,&s);
   int x,y,z;
   int ans=0;
   for(int i = 0;i < k+1;i++){
      for(int j = 0;j < k+1;j++){
         x = i;
         y = j;
         z = s-i-j;
         if(0 <= z && z <= k){
            ans++;
            //printf("%d %d %d\n",x,y,z);
         }
      }
   }
   printf("%d",ans);
}

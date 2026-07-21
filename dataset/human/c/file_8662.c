#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a > b) ? a : b
#define MIN(a,b) (a < b) ? a : b
const int inf = 1000000000; // 10^9

int main(){
   int x,a[100000];scanf("%d",&x);
   int on = 0;
   for(int i = 0;i < x;i++)scanf("%d",&a[i]);
   for(int i = 1;i <= x;i++){
      if(a[on] == 2){
         printf("%d");
         return 0;
      }
      else on = a[on]-1;
   }
   printf("-1");
   return 0;
}

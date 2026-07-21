#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
const int inf = 1000000000; // 10^9

int main(){
   char s[4];scanf("%s",s);
   int a=0,b=0,c=0;
   for(int i = 0;i < 3;i++){
      if(s[i]=='a')a++;
      else if(s[i]=='b')b++;
      else if(s[i]=='c')c++;
      else {
         printf("No");
         return 0;
      }
   }
   if(a==1&&b==1&&c==1)printf("Yes");
   else printf("No");
}

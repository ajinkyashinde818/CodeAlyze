#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
const int inf = 1000000000; // 10^9

int main(){
   int n,d,x;scanf("%d%d%d",&n,&d,&x);
   int a[101];
   int ans=0;
   for(int i = 0;i < n;i++)scanf("%d",&a[i]);
   for(int i = 0;i < n;i++){
      ans += (((d%a[i]==0)?0:1) + d/a[i]);
   }
   printf("%d",ans+x);
}

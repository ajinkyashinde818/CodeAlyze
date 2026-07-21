#include <stdio.h>
int main(){
 int i, data[10000], x;
 for(i = 0; i < 10000; i++){
  scanf("%d", &x);
  if(x == 0) break;
  data[i] = x;
  
 }
 for(i = 0; i < 10000; i++){
   printf("Case %d: %d\n", i+1, data[i]);
 }
 return 0;
}

#include <stdio.h>

int main (void){

int  a , b , k , i , s = 0;
int  w[100];

scanf("%d %d %d",&a,&b,&k);
int m   = (a<b?a:b);

for(i = 1;i <=m;i++){
   if(a%i == 0&&b%i == 0){ 
     w[s] = i;
      s++;
}}

printf("%d",w[s-k]);

return 0;
}

#include<stdio.h>

int max(int a,int b){
  int r,tmp;
  if(a<b){
   tmp = a;
   a = b;
   b = tmp;
 }
 /* ユークリッドの互除法 */
 r = a % b;
 while(r!=0){
   a = b;
   b = r;
   r = a % b;
 }
 /* 最大公約数を出力 */
 return b;
}

int main(void){
  int a,b,k,i,j;
  scanf("%d%d%d",&a,&b,&k);
  int d=max(a,b);
  for(i=1;i<=k;i++){
    for(j=d;1<=j;j--){
      if(a%j==0 && b%j==0)break;
    }
    d=j-1;
  }
  printf("%d\n",d+1);
  return 0;
}

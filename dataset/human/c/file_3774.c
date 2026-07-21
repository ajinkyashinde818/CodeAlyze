#include<stdio.h>
#define ll long long

int main(){
  ll a,b,r,tmp,x;
  scanf("%lld%lld",&a,&b);
  x=a*b;
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

  printf("%lld",x/b);
  return 0;
}

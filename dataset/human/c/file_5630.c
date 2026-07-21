#include<stdio.h>

int main(void){
  long long int X,i,ans;
  scanf("%lld",&X);
  if(X%11 == 0){
    ans=2*(X/11);
  }else if(X%11<7){
    ans=2*(X/11)+1;
  }else{
    ans=2*(X/11)+2;
  }
  printf("%lld\n",ans);
  return 0;

}

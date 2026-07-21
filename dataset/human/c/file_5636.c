#include<stdio.h>

int main(){
  long long int x;
  long long int ans;

  scanf("%lld", &x);
  if(x%11 == 0){
    ans = (x/11)*2;
  }else if(x%11<=6) {
    ans = (x/11)*2 + 1;
  }else{
    ans = (x/11)*2 + 2;
  }
  printf("%lld\n", ans);
  return 0;
}

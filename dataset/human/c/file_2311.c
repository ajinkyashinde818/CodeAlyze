#include <stdio.h>

int main(void){
  long long n,k,s;
  scanf("%lld%lld%lld",&n,&k,&s);
  if(s<1000000000){
  for(int i=0;i<n;i++){
  if(i<k) printf("%lld ",s);
  else{
    printf("%lld ",s+1);
  }
  }
  }
  if(s==1000000000){
    for(int i=0;i<n;i++){
      if(i<k) printf("%lld ",s);
    else{
      printf("1 ");
    }
    }
  }

  return 0;
}

#include<stdio.h>

int main(void){
  long long int n;
  scanf("%lld",&n);
  
  if(n%2==1){
    printf("0");
  }else{
    long long int k=0;
    n=n/2;
    while(n!=0){
      n=n/5;
      k=k+n;
    }
    printf("%lld",k);
  }
  
  return 0;
}

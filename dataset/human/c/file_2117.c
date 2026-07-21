#include <stdio.h>

long long count_zero(long long n){
  long long count;
  
  if(n <= 4){
    return 0;
  }
  else{
    count = n / 5 + count_zero(n / 5);
  }
  
  return count;
}

int main(){
  long long n;
  long long count;
  
  scanf("%lld", &n);
  
  if(n % 2 == 1){
    printf("0\n");
    return 0;
  }
  else{
    count = count_zero(n / 2);
  }
  
  printf("%lld\n", count);
  
  return 0;
}

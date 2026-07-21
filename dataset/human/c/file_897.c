#include <stdio.h>
#include <math.h>

int main(){
  long long n;
  int count = 0;
  int count_r = 0;
  
  scanf("%lld", &n);
  
  for(int i = 2; i <= sqrt(n); i++){
    if(i > n)
      break;
    
    while(n % i == 0){
      n /= i;
      count++;
    }
    
    int j = 1;
    
    while(count >= j){
      count -= j;
      count_r++;
      j++;
    }
    
    count = 0;
  }
  
  if(n > sqrt(n))
    count_r++;
  
  printf("%lld\n", count_r);
  return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main(){
  long long N;
  long long ans=0;
 
  scanf("%lld",&N);
  if(N & 1) {
      printf("0\n");
	  return 0;
  }
  
  for(long long i=10; i<= N; i*=5){
    ans += N / i;
  }
  printf("%lld\n", ans);
  return 0;

}

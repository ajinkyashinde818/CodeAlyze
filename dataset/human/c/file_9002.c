#include<stdio.h>

int main(void){
  unsigned int n,i,j,k,count;
  while(scanf("%u",&n) && n){
    count=0;
    while(n!=1){
      count+=1;
      n=(n%2)?3*n+1:n/2;
    }
    printf("%u\n",count);
  }
  return 0;
}

#include<stdio.h>
int main(){
  while(1){
    int i=0;
    long long int n;
    scanf("%lld",&n);
    if(n==0){
      break;
    }
    while(n!=1){
      if(n%2==0){
	n=n/2;
      }
      else{
	n=n*3+1;
      }
      i++;
    }
    printf("%d\n",i);
  }
  return 0;
}

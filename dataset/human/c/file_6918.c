#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


int cmp(const int *a,const int *b){

return *a > *b ? -1 : *a < *b ? 1 : 0 ;
}
//qsort(pa,n,sizeof(int),(int(*)(const void* ,const void*))cmp);

long long int memo[100];
long long int fib(int n){
  if(n<=1){
    return n;
  }
  else{
    return fib(n-1)+fib(n-2);
  }
}

long long int fib2(int n){
  if(n<=1){
    return n;
  }
  if(memo[n]!=0){
    return memo[n];
  }
    return memo[n]=fib(n-1)+fib(n-2);

}


int main(void){
  int n,m;
  scanf("%d%d",&n,&m);

  if(n==m){
    printf("Yes");
    return 0;
  }
  else{
    printf("No");
  }


  return 0;
}

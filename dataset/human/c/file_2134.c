#include<stdio.h>
int main(){
  long long n,count=0,i;
  scanf("%lld",&n);
  if(n%2!=0)
    printf("0\n");
  else{
    while(n/10!=0){
      n/=10;
      count+=n;
      i=n;
      while(i!=0){
        count=count+i/5-i/10;
        i/=5;
      }
    }
    printf("%lld\n",count);
  }
  return 0;
}

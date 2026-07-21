#include<stdio.h>
int main(){
  long long int a,b,c,ans;
  scanf("%lld %lld %lld\n",&a,&b,&c);
  if(c>a+b){
    ans=a+b+b+1;
  }
  else if(c==a+b){
    ans=a+b+b;
  }
  else{
    ans=c+b;
  }
  printf("%lld\n",ans);
  return 0;
}

#include<stdio.h>
#define ll long long

int main(){
  ll n,k,s,a[100002],i;
  scanf("%lld%lld%lld",&n,&k,&s);
  if(s!=1000000000){
    for(i=0;i<k;i++){
      printf("%lld ",s);
    }
    for(i=k;i<n;i++){
      printf("1000000000 ");
    }
  }else{
    for(i=0;i<k;i++){
      printf("%lld ",s);
    }
    for(i=k;i<n;i++){
      printf("1 ");
    }
  }
  return 0;
}

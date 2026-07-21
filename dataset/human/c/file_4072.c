#include<stdio.h>

int main(){
  int a,b,k,i,min;
  scanf("%d%d%d",&a,&b,&k);
  if(a<b){
    min=a;
  }else{
    min=b;
  }
  for(i=min;i>0;i--){
    if(a%i==0&&b%i==0){
      k--;
    }
    if(k==0){
      break;
    }
  }
  printf("%d",i);
  return 0;
}

#include<stdio.h>
int main(){
  int a,b,x,k,i,j=0,m;
  scanf("%d%d%d/n",&a,&b,&k);
  if(a>b){
      m=b;
      b=a;
      a=m;
    }
  x=b%a;
  while(x!=0){
    b=a;
    a=x;
    x=b%a;
  }
  for(i=a;j<k;i--){
    if(a%i==0){
      j++;
    }
  }
  printf("%d",i+1);
  return 0;
}

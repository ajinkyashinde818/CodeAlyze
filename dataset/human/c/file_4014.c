#include<stdio.h>
int main(){
  int a,b,k,max,i,n=0;
  scanf("%d %d %d", &a,&b,&k);
  if(a>b){
    max=b;
  } else{
    max=a;
  }
  for(i=max;i>=1;i--){
    if(a%i==0 & b%i==0){
      n++;
        if(n==k){
          break;
        }
    }
  }

  printf("%d",i);

  return 0;
}

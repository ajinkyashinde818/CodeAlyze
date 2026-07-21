#include<stdio.h>
int main(void){
  int a,b,k,n=0,i=1;
  scanf("%d %d %d",&a,&b,&k);
  if(a<b){
      i=a;
  }else{
      i=b;
  }
  while(n<k){
      if(a%i==0){
          if(b%i==0){
              n++;
          }
      }
      i--;
  }
  printf("%d",i+1);
}

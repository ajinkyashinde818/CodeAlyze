#include<stdio.h>
int main(){
  int a,b,c,d=0;
  scanf("%d %d %d",&a,&b,&c);
  for(int i=100; 1<=i; i--){
    if(a%i==0&&b%i==0){
      d++;
    }
    if(d==c){
      printf("%d",i);
      break;
    }
  }
  return 0;}

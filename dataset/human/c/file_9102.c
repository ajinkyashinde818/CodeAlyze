#include<stdio.h>

int main(void){
  int a,b,c[100000],i,j;
  scanf("%d%d",&a,&b);
  j=0;
  for(i=1;i<=a;i++){
    scanf("%d",&c[i]);
    if(b<=c[i]){
      j=j+1;
    }
  }
  printf("%d",j);
  return 0;
}

#include<stdio.h>
int min(int x,int y){
  if(x>y)
    return y;
  else
    return x;
}
int main(void){
  int A,B,K,div,c,i;
  scanf("%d %d %d",&A,&B,&K);
  div=min(A,B);
  c=0;
  for(i=div;i>=1;i--){
  if(A%i==0&&B%i==0)
    c++;
    if(c==K)
      break;
  }
  printf("%d",i);
  return 0;
}

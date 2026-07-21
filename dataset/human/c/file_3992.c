#include<stdio.h>
int min(int x,int y){
  if(x>=y)return y;
  else return x;
}
int main(void){
  int a,b,k;
  scanf("%d%d%d",&a,&b,&k);
  int c=0;
  for(int i=min(a,b);i>=1;i--){
	if(a%i==0&&b%i==0)c++;
    if(c==k){printf("%d",i);
             return 0;
            }
  }
  return 0;
}

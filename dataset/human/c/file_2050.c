#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  if(a+b>=c){
    printf("%d\n",b+c);
    return 0;
  }
  printf("%d\n",a+b+b+1);
  return 0;
}

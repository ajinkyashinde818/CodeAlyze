#include<stdio.h>
int main(){
  int n,d,x,a,i,k;
  scanf("%d%d%d",&n,&d,&x);
  for(i=1;i<=n;i++){
    scanf("%d",&a);
    k=1;
    while(k<=d){
      x++; k+=a;
    }
  }
  printf("%d\n",x);
  return 0;
}

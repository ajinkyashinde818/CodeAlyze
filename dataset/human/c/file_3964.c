#include<stdio.h>
int main(void){
  int i,a,b,k,cnt=0;
  int u[50];
  scanf("%d %d %d",&a,&b,&k);
  for(i=1;i<=100;i++){
    if(a%i==0 && b%i==0){
      //printf("%d ",i);
      u[cnt]=i;
      cnt+=1;
    }
  }
  printf("%d",u[cnt-k]);
  return 0;
}

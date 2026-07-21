#include<stdio.h>
int main(){
  int a,b,i,j=0,k,d[100]={};
  scanf("%d%d%d",&a,&b,&k);
  for(i=1;i<=100;i++){
    if(a%i==0&&b%i==0){
      j++;
      d[j]=i;
    }
  }
  printf("%d",d[j-k+1]);
}

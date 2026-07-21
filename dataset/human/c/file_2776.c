#include<stdio.h>
int main(){
  int i,j,s,k,a=0;
  scanf("%d%d",&k,&s);
  for(i=0;i<=k;i++){
    if(s-i>=0&&s-i<=k)a+=s-i+1;
    if(s-i>k&&s-i<=2*k)a+=2*k-s+i+1;
  }
  printf("%d",a);
}

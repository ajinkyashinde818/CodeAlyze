#include<stdio.h>
int main(void){
  int k,s,i,j,l,ans;
  scanf("%d%d",&k,&s);
  for(i=0;i<=k;i++){
   for(j=0;j<=k;j++){
     int l=s-i-j;  
     if(0<=l&&l<=k) ans++;
   }
  }
  printf("%d",ans);
  return 0;
}

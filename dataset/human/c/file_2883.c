#include<stdio.h>
int main(){
  int k,s,count=0;
  scanf("%d%d",&k,&s);
  
  for(int i=0;i<=k;i++){
    for(int j=0;j<=k;j++){
      int l=s-i-j;
      if(l>=0&&l<=k){
        count++;
      }
    }
  }
  
  printf("%d",count);
  return 0;
}

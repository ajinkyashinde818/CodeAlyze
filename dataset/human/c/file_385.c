#include<stdio.h>
#include<stdlib.h>

int main(){
  int n;
  int r;
  int ans;
  
  scanf("%d %d",&n,&r);
  
  if(n>=10){
  ans=r;
  printf("%d\n",ans);
  }else{
  ans=100*(10-n)+r;
  printf("%d\n",ans);
  }
  
  

  return 0;
}

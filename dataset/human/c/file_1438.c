#include <stdio.h>
#include <string.h>

int main(){
  int n,ans;
  scanf("%d",&n);
  if(n%10==9){
    ans +=1;
  }
  if(n>=90){
    ans +=1;
  }
  if(ans>=1){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}

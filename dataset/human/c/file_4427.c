#include <stdio.h>

int main(){
  int n,m;
  m = 0;
  scanf("%d",&n);
  int d1[n],d2[n];
  for(int i = 0;i<n;i++){
    scanf("%d %d",&d1[i],&d2[i]);
  }
  for(int i = 0;i<n;i++){
    if(d1[i]==d2[i]){
      m++;
    }else{
      m=0;
    }
    if(m>=3){
      break;
    }
  }
  if(m>=3){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}

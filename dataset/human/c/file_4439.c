#include <stdio.h>

int main(){
  int N;
  int D[300];
  scanf("%d", &N);
  for(int i=1;i<=N;i++){
    scanf("%d %d", D+2*i-1,D+2*i);
  }
  int c=0,ans=0;
  for(int i=1;i<=N;i++){
    if(D[2*i-1]==D[2*i]){
      c++;
    }else{
      c=0;
    }
    if(c==3){
      ans=1;
      break;
    }
  }
  
  if(ans==1) printf("Yes\n");
  else printf("No\n");
  return 0;
}

#include <stdio.h>

int main(){
  int N;
  int i=0;
  int flag = 0;
  scanf("%d",&N);
  
  int D1[N+1],D2[N+1];
  
  while(i<N){
    scanf("%d %d",&D1[i],&D2[i]);
    if(D1[i] == D2[i]) flag++;
    else flag = 0;
    if(flag >= 3){
      printf("Yes\n");
      break;
    }
    i++;
  }
  
  if(flag < 3 ) printf("No\n");
  
  return 0;
}

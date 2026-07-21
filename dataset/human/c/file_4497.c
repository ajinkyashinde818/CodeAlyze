#include<stdio.h>
int main(void){
  int N;
  scanf("%d",&N);
  int D1[N],D2[N];
  for(int i=0;i<N;i++){
    scanf("%d%d",&D1[i],&D2[i]);
  }
  int sum=0;
  for(int j=0;j<N-2;j++){
    if(D1[j]==D2[j] && D1[j+1]==D2[j+1] && D1[j+2]==D2[j+2]){
      sum=1;
      break;
    }
  }
  if(sum==1){
    printf("Yes");
  }
  else
    printf("No");
  return 0;
}

#include <stdio.h>

int main(){
  
  int N,D,X,ans = 0;
  scanf("%d%d%d",&N,&D,&X);
  
  int i,A[N],day[N]; //day[N]:i番目の人間が何日間チョコを食べるか
  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }
  
  for(i = 0 ; i < N ; i++){
    day[i] = (D - 1) / A[i] + 1;
  }
  
  int sum = 0;
  for(i = 0 ; i < N ; i++){
    sum += day[i];
  }
  
  ans = sum + X;
  printf("%d",ans);
  
  return 0;
}

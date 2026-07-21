#include <stdio.h>

int main(void){
  int N,D,X;
  scanf("%d%d%d",&N,&D,&X);
  int A;
  int ans = 0;

  for(int i = 0;i < N;i++){
    scanf("%d",&A);
    int counter = 0;
    while(A*counter+1 <= D){
      counter++;
    }
    ans += counter;
  }

  printf("%d\n",ans+X);

  return 0;
}

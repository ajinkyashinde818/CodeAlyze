#include <stdio.h>
#include <string.h>
int main(){
  int N;
  int D[100][2];
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d", &D[i][0], &D[i][1]);
  }
  for(int i=0;i<N-2;i++){
    if(D[i][0]==D[i][1] && D[i+1][0]==D[i+1][1] && D[i+2][0]==D[i+2][1]){
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
}

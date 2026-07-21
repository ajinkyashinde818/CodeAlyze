#include <stdio.h>

int main(){
  char A[55][55];
  char B[55][55];
  int N,M;
  scanf("%d %d",&N,&M);
  int i,j,x,y;
  for(i=0;i<N;i++){
    scanf("%s",A[i]);
  }
  for(i=0;i<M;i++){
    scanf("%s",B[i]);
  }
  i=0;
  j=0;
  while(1){
    if(i+M-1>=N) break;
    int cnt=0;
    for(y=0;y<M;y++){
      for(x=0;x<M;x++){
        if(A[y+i][x+j]==B[y][x])cnt++;
      }
    }
    if(cnt==M*M){
      printf("Yes\n");
      return 0;
    }
    j++;
    if(j+M-1>=N){
      i++;
      j=0;
    }
  }
  printf("No\n");
  return 0;
}

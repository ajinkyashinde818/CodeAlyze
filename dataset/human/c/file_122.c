#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int R,G,B,N;
  scanf("%d %d %d %d",&R,&G,&B,&N);
  int ans = 0;
  int **matrix;
  int row = 3000, column = 3000;
  matrix = (int **)malloc(sizeof (int*) * row);
  int i,j;
  for(i = 0; i < row+1; i++){
     matrix[i] = (int *)malloc(sizeof (int) * column);
     for(j = 0; j < column+1;j++){
       if(G*i+B*j > N){
         matrix[i][j] = -1;
       }else{
         matrix[i][j] = G*i+B*j;
       }
     }
  }

  if(N%R == 0){
    ans++;
  }

  i = 0;
  j = 1;
  while(matrix[i][0]!=-1){
    while(matrix[i][j] != -1){
      if((N-matrix[i][j])%R == 0){
        ans++;
      }
      j++;
      if(j == 3001)break;
    }
    j = 0;
    i++;
    if(i == 3001)break;
  }

  free(matrix);

  printf("%d",ans);



  return 0;
}

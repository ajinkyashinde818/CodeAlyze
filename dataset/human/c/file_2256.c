#include <stdio.h>
#define MAX 1000

int getLargestSquare(int, char G[MAX][MAX]);

main(){
  int size, i, j;
  char map[MAX][MAX];

  while(1){
    scanf("%d", &size);
    if(size==0) break;

    getchar();
    for(i=0;i<size;i++){
      for(j=0;j<size;j++){
	scanf("%c", &map[i][j]);
      }
      getchar();
    }

    printf("%d\n", getLargestSquare(size,map));
  }
  return 0;
}

int getLargestSquare(int size, char G[MAX][MAX]){
  int W[MAX][MAX];
  int i, j, maxWidth, min;

  for(i=0;i<size;i++){
    if(G[0][i]=='*') W[0][i]=0;
    else W[0][i]=1;
    if(G[i][0]=='*') W[i][0]=0;
    else W[i][0]=1;
  }

  maxWidth=0;
  for(i=1;i<size;i++){
    for(j=1;j<size;j++){
      if(G[i][j]=='*'){
	W[i][j]=0;
      }
      else{
	if(W[i-1][j-1]<=W[i-1][j] && W[i-1][j-1]<=W[i][j-1]){
	  W[i][j]=W[i-1][j-1]+1;
	}
	else if(W[i-1][j]<=W[i-1][j-1] && W[i-1][j]<=W[i][j-1]){
	  W[i][j]=W[i-1][j]+1;
	}
	else W[i][j]=W[i][j-1]+1;
	if(maxWidth<W[i][j]) maxWidth=W[i][j];     
      }
    }
  }
  return maxWidth;
}

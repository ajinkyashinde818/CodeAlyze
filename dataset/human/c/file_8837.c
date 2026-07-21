#include<stdio.h>

int main(void){
  int H,W;
  char board[52][53]={""};
  int i,j,k;
  scanf("%d%d%*c",&H,&W);
  for(i=1;i<=H;i++){
    scanf("%s%*c",board[i]+1);
    board[i][0]=board[i][W+1]='.';
    board[i][W+2]='\0';
  }
  for(i=0;i<=W+1;i++){
    board[0][i]=board[H+1][i]='.';
  }
  board[0][W+2]=board[H+1][W+2]='\0';

  for(i=1;i<=H;i++){
    for(j=1;j<=W;j++){
      if(board[i][j]=='.') continue;
      if(board[i-1][j]=='.' && board[i+1][j]=='.' &&
	 board[i][j-1]=='.' && board[i][j+1]=='.'){
	puts("No");
	return 0;
      }
    }
  }
  puts("Yes");
  return 0;
}

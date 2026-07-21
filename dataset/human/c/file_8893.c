#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*w+(j))

int cond(char *board,int h,int w){
  int i,j;
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(board[POS(i,j)]=='.') continue;
      int d[]={1,0,-1,0,1};
      int k;
      for(k=0;k<4;k++){
	int x=i+d[k];
	int y=j+d[k+1];
	if(x>=0 && x<h && y>=0 && y<w && board[POS(x,y)]=='#') break;
      }
      if(k==4) return 0;
    }
  }
  return 1;
}

void run(void){
  int h,w;
  scanf("%d%d",&h,&w);
  char board[2501];
  int i;
  for(i=0;i<h;i++) scanf("%s",board+POS(i,0));
  printf("%s\n",cond(board,h,w)?"Yes":"No");
}

int main(void){
  run();
  return 0;
}

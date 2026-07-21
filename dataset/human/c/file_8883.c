#include <stdio.h>

int main(){
  int H,W;
  scanf("%d%d\n",&H,&W);
  char s[H+2][W+2];//隣接マスを見るため添字0,maxをピリオドで埋める
  char bin;// \n
  for(int i = 0; i < H + 2; ++i){
	s[i][0] = '.';
	s[i][W + 1] = '.';
  }
  for(int j = 0; j < W + 2; ++j){
	s[0][j] = '.';
	s[H + 1][j] = '.';
  }
  for(int i = 1; i < H + 1; ++i){
	for(int j = 1; j < W + 1; ++j){
	  scanf("%c", &s[i][j]);
	}
    scanf("%c", &bin);
  }
  int flag = 0;
  for(int i = 1; i < H + 1; ++i){
	for(int j = 1; j < W + 1; ++j){
	  if(s[i][j] == '#'){
		if(s[i-1][j]=='.'&&s[i+1][j]=='.'&&s[i][j-1]=='.'&&s[i][j+1]=='.') flag = 1;
	  }
	}
  }
  if(flag == 0) printf("Yes\n");
  else printf("No\n");
  return 0;
}

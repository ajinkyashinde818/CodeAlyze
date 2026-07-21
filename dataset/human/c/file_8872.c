#include<stdio.h>

#define ok 1
#define ng 0

  int h,w;
  int judge_flag = ok;
  char map[51][51];

void judge(int i, int j){

  int flag = 0;

  if(i != 0){
    if(map[i-1][j] == '#') flag = 1;
  }

  if(i != h){
    if(map[i+1][j] == '#') flag = 1;
  }

  if(j != 0){
    if(map[i][j-1] == '#') flag = 1;
  }

  if(j != w){
    if(map[i][j+1] == '#') flag = 1;
  }

  if(flag == 1){
     return;
  }else{
    judge_flag = ng;
    return;
  }
}

int main(){


  scanf("%d %d",&h,&w);

  for(int i = 0; i < h; ++i){
    scanf("%s",map[i]);
  }

  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      if( map[i][j] == '#' ) judge(i,j);
      if( judge_flag == ng ){
        printf("No");
        return 0;
      }
    }
  }

  printf("Yes");
  return 0;

}

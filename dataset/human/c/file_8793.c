#include <stdio.h>
int main(void){
  int h,w,flag;
  scanf("%d %d",&h,&w);
  char grid[h][w] ={'a'};
  char dummy;
  for(int i = 0;i < h;i++){
    scanf("%c",&dummy);
    for(int j = 0;j < w;j++){
      scanf("%c",&(grid[i][j]));
    }
  }
    flag = 0;
    for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      if(grid[i][j] == '#'){
        if(i != 0){
          if(grid[i-1][j]=='#')continue;
        } 
        if(i != h-1){
          if(grid[i+1][j]=='#')continue;
        }
        if(j != 0){
          if(grid[i][j-1]=='#')continue;
        }
        if(j != w-1){
          if(grid[i][j+1]=='#')continue;
        }
        flag = 1;
        h = i;
        w = j;
        break;
      }
    }
    if(flag)break;
  }
  if(flag){
    printf("No");
  }else{
    printf("Yes");
  }
}

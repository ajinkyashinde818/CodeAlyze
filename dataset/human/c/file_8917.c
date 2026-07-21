#include<stdio.h>
int main(){
  int h,w;
  scanf("%d %d",&h,&w);
  char s[h][w],dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
  for(int i = 0;i < h;i++){
    scanf("%s",&s[i]);
  }
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      if(s[i][j] == '#'){
        int c = 0;
        for(int d = 0;d < 4;d++){
          int x = i + dx[d],y = j + dy[d];
          if(-1 < x && x < h && -1 < y && y < w && s[x][y] == '#'){
            c = 1;
          }
        }
        if(c < 1){
          printf("No\n");
          return 0;
        }
      }
    }
  }
  printf("Yes\n");
  return 0;
}

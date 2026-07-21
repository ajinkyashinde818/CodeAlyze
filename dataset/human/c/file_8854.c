#include<stdio.h>

int h,w;
char field[101][101]={'a'};

int dfs(int x,int y){
  for(int dx=-1;dx<=1;dx+=2){
    int nx=x+dx;
    if(0<=nx && nx<h && field[nx][y]=='#')return 1;
  }
  for(int dy=-1;dy<=1;dy+=2){
    int ny=y+dy;
    if(0<=ny && ny<w && field[x][ny]=='#')return 1;
//        puts("yes");
  }
  return 0;
}


int main(){
  scanf("%d%d\n",&h,&w);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      scanf(" %c",&field[i][j]);
    }
  }
//  int ans=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(field[i][j]=='#'){
        int flg = dfs(i,j);
        //printf("%d\n",flg);
        if(flg==0){
          puts("No");
          return 0;
        }
//        printf("%d\n",ans);
      }
    }
  }
  puts("Yes");
  return 0;
}

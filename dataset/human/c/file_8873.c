#include <stdio.h>

int h, w;
char field[51][51] = {};
int already[51][51] = {};

int flag = 0;

void check_field(int x, int y){

  if(x < 0 || x >= w || y < 0 || y >= h) return;

  //すでに調査済みなら
  if(already[y][x] == 1) return ;

  already[y][x] = 1;

  if(field[y+1][x] == '.' && field[y-1][x] == '.' && field[y][x-1] == '.' && field[y][x+1] == '.'){
    flag = 1;
  }

  return;
}

int main(){
  int i, j;

  scanf("%d %d", &h, &w);

  for(i = 0; i < h; i++){
    scanf("%s", field[i]);
  }

  for(i = 0; i < h; i++){
    for(j = 0; j < w; j++){
      if(field[i][j] == '#' && already[i][j] == 0) check_field(j,i);
    }
  }

  if(flag == 1){
    printf("No");
  } else {
    printf("Yes");
  }

  return 0;
}

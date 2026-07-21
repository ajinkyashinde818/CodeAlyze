#include<stdio.h>

int main(){
  int h, w;
  scanf("%d %d ", &h, &w);
  
  int grid[h + 1][w + 1];
  
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      char c;
      scanf("%c ", &c);
      
      grid[i][j] = (c == '#') ? -1 : 0;
    }
  }
  
  for(int i = 0; i <= h; i++){
    grid[i][w] = 0;
  }
  
  for(int j = 0; j < w; j++){
    grid[h][j] = 0;
  }
  
  int result = 1;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(grid[i][j] == -1){
        if(grid[i + 1][j] == 0 && grid[i][j + 1] == 0){
          result = 0;
          break;
        }else{
          if(grid[i + 1][j] == -1) grid[i + 1][j] = 1;
          if(grid[i][j + 1] == -1) grid[i][j + 1] = 1;
        }
      }else if(grid[i][j] == 1){
        if(grid[i + 1][j] == -1) grid[i + 1][j] = 1;
        if(grid[i][j + 1] == -1) grid[i][j + 1] = 1;
      }
    }
    
    if(!result) break;
  }
  
  if(result) puts("Yes");
  else puts("No");
  
  return 0;
}

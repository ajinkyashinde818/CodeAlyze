#include <stdio.h>

#define YES 0
#define NO 1

int main(void){
  char grid[51][52];
  int h,w;
  int i,j;
  int judge = YES;
  
  scanf("%d %d\n",&h,&w);
  
  /* Init */
  for( i=0; i<51; i++) for( j=0; j<51; j++){
      grid[i][j] = '.';
  }
  
  for( i=1; i<=h; i++) for( j=1; j<=w+1; j++){
      scanf("%c",&grid[i][j]);
  }
  
  //Delete NULL
  for( i=0; i<=h; i++) grid[i][w+1] = '.';
  
  for( i=1; i<=h; i++) for( j=1; j<=w; j++){
      if( grid[i][j] == '#' &&
          grid[i-1][j] == '.' &&
          grid[i+1][j] == '.' &&
          grid[i][j-1] == '.' &&
          grid[i][j+1] == '.' ) judge = NO;
  }
    
  (judge == YES) ? printf("Yes\n") : printf("No\n") ;
  
  return 0;
}

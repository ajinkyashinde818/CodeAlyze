#include <stdio.h>

int main(void){
  
  int h , w;
  scanf("%d %d",&h ,&w);
  
  char s[h][w];
  for(int i = 0;i < h;i ++){
      scanf("%s",s[i]);
  }
  
  int ans = 0 , flag = 0;

  for(int i = 0;i < h;i ++){
    for(int j = 0;j < w;j ++){
      if(s[i][j] == '#'){
        if(s[i-1][j] == '#' && i - 1 >= 0){
          ans ++;
        }
        if(s[i][j - 1] == '#' && j -1 >= 0){
          ans ++;
        }
        if(s[i][j + 1] == '#' && j + 1 < w){
          ans ++;
        }
        if(s[i + 1][j] == '#' && i + 1 < h){
          ans ++;
        }
        if(ans == 0){
          flag ++;
        }
        ans = 0;
      }
    }
  }
  
  if(flag == 0){
   printf("Yes\n");
  }
  else{
    printf("No\n");
  }

  return 0;
}

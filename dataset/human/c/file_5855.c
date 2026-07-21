#include <stdio.h>

int main(void){
  int n;
  int r;
  int i;
  int min, max;
  int min_sub;
  
  //input
  scanf("%d", &n);

  //main
  for(i = 0; i < n; i++){
    scanf("%d", &r);
    if(i == 0){
      min = r;
      min_sub = r;
    }else if(i == 1){
      max = r;
      if(min > r){
        min_sub = r;
      }
    }else{
      if(r > max){
        max = r;
        if(max - min < r - min_sub){
          max = r;
          min = min_sub;
        }
      }else if(r < min_sub){
        min_sub = r;
      }else{
        if(max - min < r - min_sub){
          max = r;
          min = min_sub;
        }
      }
    }
  }
  
  //output
  printf("%d\n", max - min);
  return 0;
}

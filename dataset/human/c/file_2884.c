#include <stdio.h>

int main(){
  int set_num = 0;
  int max, sum;
  scanf("%d %d", &max, &sum);
  for(int i = 0; i <= max; i++){
    for(int j = 0; j <= max; j++){
      int z = sum - i - j;
      if(z >= 0 && z<= max){
        set_num += 1;
      }
    }
  }

  printf("%d\n", set_num);
  return 0;
}

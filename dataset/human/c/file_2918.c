#include <stdio.h>

int main(void){
  int k, s, x, y, z;
  scanf("%d %d", &k, &s);
  int num = 0;
  for(x = 0; x <= k; x++){
    for(y = 0; y <= k; y++){
      z = s - x - y;
      if(z >= 0 && z <= k) num++;
    }
  }

  printf("%d\n", num);
  return 0;
}

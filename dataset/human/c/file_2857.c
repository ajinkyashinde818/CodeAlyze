#include <stdio.h>
#include <stdlib.h>
int main(){
  int *k = malloc(sizeof(int)), *s = malloc(sizeof(int));
  int resp = 0;
  scanf("%d%d", k, s);
  for(int x = 0;x <= *k;++x){
    for(int y = 0; y <= *k;++y){
      int z = (*s)-x-y;
      if (*k >= z && z >= 0) ++resp;
    }
  }
  printf("%d\n",resp);
  free(k);
  free(s);
}

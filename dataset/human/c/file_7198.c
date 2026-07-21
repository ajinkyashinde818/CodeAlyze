#include <stdio.h>

int main(void){

  int h, w, i, ii, a;

  for(a = 0; a < 1; a--){
    scanf("%d%d", &h, &w);
    if (h == 0 && w == 0) break;
    for(i = 0; i < h; i++){
      for(ii = 0; ii < w; ii++){
	if(i % 2 == 0){
	  if(ii % 2 != 0) printf(".");
	  else printf("#");
	} else {
	  if(ii % 2 == 0) printf(".");
	  else printf("#");
	}
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}

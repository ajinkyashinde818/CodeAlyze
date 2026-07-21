#include <stdio.h>
#include <math.h>

int main(void){

  int h, w;
  int i, j;

  for(;;){
    scanf("%d %d", &h, &w);

    if(h == 0 && w == 0) break;
  
    for(i = 0; i < h; i++){
      for(j = 0; j < w; j++){
	if(i % 2 == 0){
	  if(j % 2 == 0) printf("#");
	  else printf(".");
	}else{
	  if(j % 2 == 0) printf(".");
	  else printf("#");
	}
	if(j == w-1) printf("\n");
      }
      if(i == h-1) printf("\n");
    }
  }

  return 0;

}

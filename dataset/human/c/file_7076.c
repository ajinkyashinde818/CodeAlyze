#include <stdio.h>

int main(){
  int h,w;
  int i,j;
  while(1){
    scanf("%d %d", &h, &w);
    if(h == 0 && w == 0){
      break;
    }
    for(i = 1; i <= h; i++){
      for(j = 1; j<= w; j++){
	if(i % 2 == 0){
	  if(j % 2 == 0){
	    printf("#");
	  }else{
	    printf(".");
	  }
	}else{
	  if(j % 2 == 0){
	    printf(".");
	  }else{
	    printf("#");
	  }
	}
      }
      putchar('\n');
    }
    putchar('\n');
  }
  return 0;
}

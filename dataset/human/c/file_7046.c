#include <stdio.h>

int main(void)
{
  int H, W, i, j, k;
  while(1){
    scanf("%d %d", &H, &W);
    if(H == 0 && W == 0){
      break;
    }else{
      for(i = 1; i <= H; i++){
	if(i % 2){
	  for(j = 1; j <= W; j++){
	    if(j % 2){
	      putchar('#');
	    }else{
	      putchar('.');
	    }
	  }
	  putchar('\n');
	}else{
	  for(k = 1; k <= W; k++){
	    if(k % 2){
	      putchar('.');
	    }else{
	      putchar('#');
	    }
	  }
	  putchar('\n');
	}
      }
      putchar('\n');
    }
  }

  return 0;
}

#include<stdio.h>
int main(){

  int h, w, i, j;

  scanf("%d %d",&h, &w);

  while(1){
    for(i = 0; i < h; i++){
      if(i % 2 == 0){
	for(j = 0; j < w; j++){
	  if(j == w - 1){
	    if(j % 2 == 0){
	      printf("#\n");
	    }else{
	      printf(".\n");
	    }
	  }else if(j % 2 == 0){
	    printf("#");
	  }else{
            printf(".");
          }
	}
      }else{
	for(j = 0; j < w; j++){
	  if(j == w - 1){
	    if(j % 2 != 0){
	      printf("#\n");
	    }else{
	      printf(".\n");
	    } 
	  }else if(j % 2 != 0){
	    printf("#");
          }else{
            printf(".");
          }
	}
      }
    }

  scanf("%d %d",&h, &w);
  printf("\n");
  if(h == 0 || w == 0){
    break;
  }

  }

  return 0;
}

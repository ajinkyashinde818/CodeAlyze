#include<stdio.h>

//this file is not a C file but a C++ file

int main(void){
  int H = 0;//Height
  int W = 0;//Width

  bool flg = false;//flg to end this program
  do{
    scanf("%d %d", &H, &W);
    
    if(H == 0 && W == 0){
      flg = true;
    }else{

      for(int i = 0; i < H; i++){
	for(int j = 0; j < W; j++){
	  
	  if((i + j)%2 == 0){
	   
	    if(j == W - 1){
	      printf("#\n");
	    }else{
	      printf("#");
	    }

	  }else{

	    if(j == W -1){
	      printf(".\n");
	    }else{
	      printf(".");
	    }

	  }

	}
      }
      printf("\n");
    }

  }while(!flg);

}

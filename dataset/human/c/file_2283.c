#include <stdio.h>
#include <stdlib.h>

  int main(void){

        int x;
	scanf("%d",&x);


	if(x < 1 || 3000 < x){
	  printf("存在しません\n");
	  exit(0);

	}else if(x < 1200){

	   printf("ABC\n");

	}else if(x <= 3000){

	   printf("ARC\n");

}

}

#include<stdio.h>

int main(){

  int n, i, z;

  for(i = 0;i < 50;i++){ 

    scanf("%d", &n);

    if(n == 0)
      break;

    else{

      z = 0;

      while(n != 1){

	if(n % 2 == 0){
	
	  n = n / 2;
	  z += 1;
	
	}else if(n % 2 == 1){
	
	  n = n * 3 + 1;
	  z += 1;
	
	}

      }

	printf("%d\n", z);
	  

    }

  }


    return 0;

}

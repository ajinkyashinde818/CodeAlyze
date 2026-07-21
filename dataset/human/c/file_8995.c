#include <stdio.h>

int main(int argc, char *argv[]){

  for(;;){
    int count = 0;
    int n;
    scanf("%d", &n);

    if(n == 0){
      break;
    }

    while(n != 1){
      if(n % 2 == 0){
	n /= 2;
      }else{
	n = n*3 + 1;
      }
      count++;
    }

    printf("%d\n",count);
    
  }
  
  return 0;    
}

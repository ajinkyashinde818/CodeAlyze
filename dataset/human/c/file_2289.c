#include <stdio.h>
#include <stdlib.h>

 int main (void) {
    int x;
    
    //printf("1~3000までの整数を入力してください\n");
     scanf("%d",&x);
    
    if(x<1 || x>3000){
    printf("1~3000までの整数を入力してください");
    exit(0);
    }
      
    if(x<1200){
    printf("ABC\n");
    return 0;
    }else{
    printf("ARC\n");
    return 0;
    }
   }

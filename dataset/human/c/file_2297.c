#include <stdio.h> 
    #include <stdlib.h>    
    	int main(void){
    	int x;
    	char a;
    	scanf("%d",&x);
    	scanf(" %c", &a);
    		if(1<= x || 3000>= x){
    			if(x < 1200){
    			printf("ABC\n");
    			return 0;
      		}else{
      		printf("ARC\n");
      		return 0;
      		}	
      	}else{
      		exit(1);
      	}
    	}

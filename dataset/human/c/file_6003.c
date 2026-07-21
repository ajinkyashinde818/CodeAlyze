#include<stdio.h>
#include<stdlib.h>

int main(void){

  int x,i,a,b;
    
    scanf("%d", &x);
    
   int *array = malloc(sizeof(int)*x);
    
  
    for(i=0;i<x;i++) {
        scanf("%d", array+i);
    }
    
     a = -1.0e9;
     b = *array;
    
    for(i=1;i<x;i++) {
        if(*(array+i)-b > a) {
            a = *(array+i)-b;
        }
        if(*(array+i) < b) {
            b = *(array+i);
        }
    }
    
    printf("%d\n", a);
    
    free(array);
    
    return 0;
}

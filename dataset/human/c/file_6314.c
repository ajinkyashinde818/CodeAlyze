//Maximum Profit

#include<stdio.h>

int main(void){
    int n,i;
    long min, x;
    long difference = 0;
    
    scanf("%d", &n);
    
    scanf("%ld", &x); min = x;
    scanf("%ld", &x);
    difference = x -min;
    if(min > x) min = x;
    
    for(i = 2; i < n; i++){
        scanf("%ld", &x);
        if(min > x) 
            min = x;
        else if(x - min > difference) difference = x - min;
        
    }
    
    printf("%ld\n", difference);
    
    return 0;
}

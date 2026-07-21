#include <stdio.h>
int main(){
    long n, min = 0, diff = -1;
    scanf("%ld", &n);
    long input[200000];
    for (int i=0; i < n; i++){
        scanf("%ld", &input[i]);
    }
    //
    min = input[0];
    for(int i = 1; i < n; i++){
        if(input[i] - min > diff){
            diff = input[i] - min;
        }
        if(i == 1){
            diff = input[i] - min;   
        }
        if(input[i] < min){
            min = input[i];
        }
    }
    printf("%ld\n", diff);
    return 0;    
}

#include <stdio.h>

int main(void){
    long suuti1,suuti2,value1,value2,remainder,LCM;
    
    scanf("%ld %ld",&suuti1,&suuti2);
    
    if (suuti1 > suuti2) {
        value1 = suuti1;
        value2 = suuti2;
    } else {
        value1 = suuti2;
        value2 = suuti1;
    }
    
    while (1) {
        remainder = value1 % value2;
        if (remainder == 0 ||remainder ==1) break;
        value1 = value2;
        value2 = remainder;
    }
    
    if (remainder == 0) {
        LCM = (suuti1*suuti2) / value2;
    } else {
        LCM = (suuti1*suuti2) / remainder;
    }
    
    printf("%ld\n",LCM);
    
    return 0;
}

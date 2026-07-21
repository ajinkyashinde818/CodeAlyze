#include <stdio.h>
int main(void){
    long long int i, n, s = 1, result = 0;
    
    scanf("%lld", &n);
    
    if( n % 2 == 1 ){
        printf("0\n");
        return 0;
    } 
    
    for( i = 5; s > 0; i *= 5  ){
        s = n / (i*2);
        result += s;
    }
    
    printf("%lld\n", result);
}

// 1_1_D
#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(){
    long n, i, price;
    long min_price = LONG_MAX, max_prof = LONG_MIN;
    scanf("%ld", &n);
    for(i = 0; i < n; i++){
        scanf("%ld", &price);
        max_prof = fmaxl(max_prof, price - min_price);
        min_price = fminl(min_price, price);
    }

    printf("%ld\n", max_prof);
    return 0;
}

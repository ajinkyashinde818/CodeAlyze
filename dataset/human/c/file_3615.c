#include <stdio.h>

/*
回答の方針
1. gcc(A, B)を求める
2. gcc(A, B) * (A / gcc(A, B)) * (B / gcc(A, B)) が最小公倍数となる
*/

long int gcc(int a, int b){
    // Euclidean Algorithm
    if (a < b) {
       int tmp = b;
       b = a;
       a = tmp;
    }
    
    if (a % b == 0){
        return b;
    }else{
        return gcc(b, a % b);
    }
}

int main(void){
    int a, b;
    long int gc;
    
    scanf("%d %d", &a, &b);
    gc = gcc(a, b);
    printf("%ld", gc*(a/gc)*(b/gc));
    
    return 0;
}

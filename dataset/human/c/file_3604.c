#include<stdio.h>

int gcd(int a, int b){
    int tmp = a%b;
    if(tmp==0) return b;
    
    a=b;
    b=tmp;
    
    return gcd(a, b);
}

int main(void){
    int A, B;
    long ans;
    
    scanf("%d %d", &A, &B);
    
    ans = gcd(A, B);
    
    printf("%ld", (A/ans)*B);
}

#include <stdio.h>

int gcd(int a, int b){
    if(a < b){
        int t = a;

        a = b;
        b = t;
    }
    while(b > 0){
        int t = b;

        b = a % b;
        a = t;
    }
    return a;
}

int main(){
    long long int A, B;

    scanf("%lld%lld", &A, &B);
    printf("%lld\n", A * B / gcd((int) A, (int) B));
}

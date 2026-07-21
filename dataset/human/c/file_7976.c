#include <stdio.h>

long long int calc(long long int a, long long int b, long long int p){
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        long long int d = calc(a, b / 2, p);

        return (d * d) % p;
    } else {
        return (a * calc(a, b - 1, p)) % p;
    }
}
long long int conb(long long int a, long long int b, long long int p){
    long long int sum = 1;

    for(long long int i = 1; i <= b; i ++){
        sum = (sum * (a - i + 1)) % p;
        sum = (sum * calc(i, p - 2, p)) % p;
    }
    return sum;
}

int main(){
    int X, Y;

    scanf("%d%d", &X, &Y);

    if((- X + 2 * Y) >= 0 && (2 * X - Y) >= 0 && (- X + 2 * Y) % 3 == 0 && (2 * X - Y) % 3 == 0){
        int a = (- X + 2 * Y) / 3;
        int b = (2 * X - Y) / 3;

        printf("%lld\n", conb(a + b, b, 1000000007));
    }else{
        printf("0\n");
    }
}

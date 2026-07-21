#include<stdio.h>
#include<math.h>

int main(){
    long long int n;
    scanf("%lld", &n);
    if(n%2 == 1 || n < 10){
        printf("0");
    }else{
        long long int x = 0;
        long long int f=10;
        while(f <= n){
            x += n / f;
            f *= 5;
        }
        printf("%lld", x);
    }

    return 0;
}

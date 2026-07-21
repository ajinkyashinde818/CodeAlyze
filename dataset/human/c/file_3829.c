#include <stdio.h>

int main(void){
    long long int a,b;
    scanf("%lld",&a);
    scanf("%lld",&b);
    long long int x = a * b;
    long long int tmp,r;
    if(a<b){
    tmp = a;
    a = b;
    b = tmp;
    }

    r = a % b;
    while(r!=0){
    a = b;
    b = r;
    r = a % b;
    }
    printf("%lld\n",x/b);
    return 0;
}

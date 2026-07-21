#include<stdio.h>

void swap(long long int* a,long long int* b){
    long long int c=*a;
    *a=*b;
    *b=c;
}

long long int gcd(long long int a, long long int b){
    if(a<b){
        swap(&a,&b);
    }while(a%b!=0){
        long long int c=a%b;
        a=b;
        b=c;
    }
    return b;
}

int main(){
    long long int a, b;
    scanf("%lld%lld", &a, &b);
    printf("%lld", a*b / gcd(a, b));

    return 0;
}

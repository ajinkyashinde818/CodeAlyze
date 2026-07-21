#include<stdio.h>
long euclidean(long a,long b){
    if(a%b == 0) return b;
    else return euclidean(b,a%b);
    return 0;
}

int main(){
    long a,b,tmp;
    long gcd;
    scanf("%ld %ld",&a,&b);
    long lcd = a*b;
    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }
    gcd = euclidean(a,b);
    lcd /= gcd;
    printf("%ld\n",lcd);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long gcd(unsigned long long x, unsigned long long y){
    return y == 0 ? x : gcd(y, x % y);
}

unsigned long long lcm(unsigned long long x,unsigned long long y){
    return x / gcd(x,y) * y;
}

int main(){
    unsigned long long i,n,m,total=1;
    scanf("%lld %lld",&n,&m);
    unsigned long long a[n];
    for (i=0; i<n; i++){
        scanf(" %lld",&a[i]);
        a[i]/=2;
        total=lcm(total, a[i]);
    }
    for(i = 0; i < n; i++)
        if(total / a[i] % 2 == 0){
            printf("0\n");
            return 0;
        }
    printf("%lld\n",(m/total+1)/2);
    return 0;
}

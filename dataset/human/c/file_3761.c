#include<stdio.h>

long gcd(long a, long b){
    if(b==0){
        return a; 
    }
    return gcd(b, a%b);
}

long main(){
    long ans, a, b, tmp;
    scanf("%ld %ld",&a, &b);
    
    if(a>b){
        tmp=a;
        a=b;
        b=tmp;
    }
    long ab=a*b;
    ans = ab/gcd(a,b);

    printf("%ld\n",ans);
    
    return 0;
}

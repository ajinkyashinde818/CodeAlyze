#include <stdio.h>
long gcd(long a, long b){
        // not zero
        char p=0;
        while(1){
        if(a%2==0){
                a/=2;
                if(b%2==0){
                        b/=2;
                        p++;
                }
        }else{
                if(b%2==0){
                        b/=2;
                }else{
                        if(a>b){
                                a-=b;
                                if(a==0) return b<<p;
                        }else{
                                b-=a;
                                if(b==0) return a<<p;
                        }
                }
        }
        }
}
int main(void){ 
        long a, b, c;
        scanf("%ld%ld", &a, &b);
        c = gcd(a, b);
        printf("%ld\n", a*b/c);
}

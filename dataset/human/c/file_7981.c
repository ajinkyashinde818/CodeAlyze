#include<stdio.h>
#define MOD (1000000007)

static inline long mdadd(long a,long b){
    return (a+b) % MOD;
}

static inline long mdml(long a,long b){
    long long res  = (long long)a * b;
    return res % MOD;
}

static inline long mdpow(long num,long ind){
    unsigned long c = (unsigned long)ind;
    long res = 1l;
    while(c){
        if(c & 1u)res = mdml(res,num);
        num = mdml(num,num);
        c >>= 1;
    }
    return res;
}

static inline long mdnck(long n,long k){
    long tmp = 1;
    register long i;
    for(i = 1;i <= k;i++)tmp = mdml(tmp,i);
    for(i = 1;i <= (n-k);i++)tmp = mdml(tmp,i);
    tmp = mdpow(tmp,MOD - 2);
    long tmp2 = 1;
    for(i = 1;i <= n;i++)tmp2 = mdml(tmp2,i);
    return mdml(tmp,tmp2);
}

int main(void){
    long x,y;
    scanf("%ld %ld",&x,&y);
    if((x+y)%3){
        puts("0");
        return 0;
    }
    long n,k;
    n = (2 * y - x) / 3;
    k = (2 * x - y) / 3;
    if(n < 0 || k < 0){
        puts("0");
        return 0;
    }
    printf("%ld",mdnck(n+k,k));
    return 0;
}

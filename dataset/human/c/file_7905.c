#include<stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

typedef unsigned long long ull;

ull gcd(ull a,ull b){
    ull max,min,r;
    min = MIN(a,b);
    max = MAX(a,b);
    while (min){
        r = max;
        r %= min;
        max = min;
        min = r;
    }
    return max;
}

ull lcm(ull a,ull b){
    return a/gcd(a,b) * b;
}

int main(void){
    int n;
    long m;
    scanf("%d %ld",&n,&m);
    long ar[n];
    for(int i = 0;i < n;i++)scanf("%ld",&ar[i]);
    for(int i = 0;i < n;i++){
        ar[i] /= 2;
        if(ar[i] != 16384 && ar[i] != 278528)fprintf(stderr,"number of %ld\n",ar[i]);
    }
    ull lcmnum = 1;
    for(int i = 0;i < n;i++)lcmnum = lcm(lcmnum,ar[i]);
    fprintf(stderr,"lcmnum = %llu",lcmnum);
    ull ans = ((m/lcmnum)+1llu)/2llu;
    for(int i = 0;i < n;i++)if(!(lcmnum / ar[i] % 2))ans = 0ull;
    printf("%llu",ans);
    return 0;
}

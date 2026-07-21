#include<stdio.h>
int main() {
    long long int k;
    long long int n;
    long long int a=0;
    long long int b=0;
    long long int c=0;
    long long int max=0;
    long long int p=0;
    long long int q=0;
    scanf("%lld %lld", &k, &n);
    for(long long int i=1;i<=n;i++) {
        a=b;
        scanf("%lld", &b);
        c=b-a;
        if(max<c) max=c;
        if(i==1) p=b;
        if(i==n) q=b;
        
    }
    if(max<p+k-q) max=p+k-q;
    printf("%lld", k-max);
}

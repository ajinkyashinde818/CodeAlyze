#include <stdio.h>
int gcd(int a,int b){
    if(b>a){
        int tmp=a;
        a=b;
        b=tmp;
    }
    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
long long lcm(int a,int b){
    long long tmp=gcd(a,b);
    return (long long)a*b/tmp;
}
int main()
{   int a,b;
    scanf("%d%d",&a,&b);
    long long ans=lcm(a,b);
    printf("%lld",ans);
    return 0;
}

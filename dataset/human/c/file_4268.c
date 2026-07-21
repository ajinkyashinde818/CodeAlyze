#include<stdio.h>
#include<stdlib.h>

int main(){
    long long n,m,d[100000],a,b=0,p=1;
    scanf("%lld %lld",&n,&m);
    d[0]=1;
    d[1]=1;
    for(int i=2;i<=n;i++){
        d[i]=d[i-1]+d[i-2];
        d[i]%=1000000007;
    }
    for(int i=0;i<m;i++){
        scanf("%lld",&a);
        if(a==b){
            printf("0\n");
            exit(0);
        }
        a=a-1;
        p*=d[a-b];
        p%=1000000007;
        b=a+2;
    }
    p*=d[n-b];
    p%=1000000007;
    printf("%lld\n",p);
    return 0;
}

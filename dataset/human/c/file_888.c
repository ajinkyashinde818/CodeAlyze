#include<stdio.h>

int isnp[1001001] = {1,1};
int ecnt[1001001];

int main(void){
    register long i,j;
    for(i = 2;i < 1001001;i++)if(!isnp[i])for(j = 2;i*j < 1001001;j++)isnp[i*j] = 1;
    long long n;
    scanf("%lld",&n);
    if(n == 1){
        puts("0");
        return 0;
    }
    static int nispf;
    for(i = 2;i < 1001001;i++)if(!isnp[i])while(!(n % i)){n /= i;ecnt[i]++;}
    if(n != 1)nispf = 1;
    static long long ans;
    for(i = 2;i < 1001001;i++)if(ecnt[i]){
        j = 1;
        do{ecnt[i] -= j;ans++;}while(ecnt[i] >= ++j);
    }
    if(nispf)ans++;
    printf("%lld",ans);
}

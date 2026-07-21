#include <stdio.h>
#include <math.h>
int cnt[1000000];
int main(void){
    long long n,i,j,ans=0;
    scanf("%lld",&n);
    for(i=2;i<sqrt(n);i++){
        if(n==1) break;
        j = 1;
        while(n%i==0){
            n/=i;
            cnt[i-1]++;
            if(cnt[i-1]==j){
                ans++;
                j++;
                cnt[i-1]=0;
            }
        }
    }
    if(n!=1) ans++;
    printf("%lld",ans);
}

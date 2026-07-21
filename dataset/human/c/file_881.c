#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    long long n,ans=0;
    scanf("%lld",&n);
    if(n==1){
        printf("0");
        return 0;
    }
    long long CN=n;
    for(long long i=2;i<=sqrt(CN)+1;i++){
        if(n%i==0){
            long long cnt=0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            for(long long j=1;cnt>=j;j++){
                cnt-=j;
                ans++;
            }
            
        }
    }
    if(n>1)ans++;
    printf("%lld",ans);
    
    return 0;
}

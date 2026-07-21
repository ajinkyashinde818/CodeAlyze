#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    long long int x,count=0,ans=0;
    scanf("%ld",&x);
    ans = 2 *  (x / 11);
    if(x % 11 == 0){
        printf("%lld",ans);
        return 0;
    }
    if(x % 11 > 6){
        printf("%lld",ans+2);
        return 0;
    }
    else printf("%lld",ans+1);
    return 0;
}

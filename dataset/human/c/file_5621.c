#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
    long long int x,ans=0,mod;
    scanf("%lld",&x);
    ans=((x-1)/11)*2+2;
    mod=x%11;
    if(mod<=6 &&mod>=1)ans--;
    printf("%lld",ans);
    
    return 0;
}

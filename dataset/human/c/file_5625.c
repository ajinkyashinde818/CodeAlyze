//(5)6565656ってくりかえす

#include <stdio.h>
int main(void){
    unsigned long long int x,ans,rui;
    scanf("%lld",&x);
    ans=0;
    ans=x/11;
    ans*=2;
    rui=(ans/2)*11;
    if(x-rui>=1 && x-rui<=6){
        ans+=1;
    }else if(x-rui>=7){
        ans+=2;
    }
    printf("%lld\n",ans);
    
    return 0;
    
}

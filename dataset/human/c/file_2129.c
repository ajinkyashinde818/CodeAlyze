#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
int main(){
    long long i,n,ans=0,five[25]={};
    scanf("%lld",&n);
    five[0]=10;
    if(n%2==1){
        printf("0");
        return 0;
    }
    for(i=1; i<25; i++){
        five[i]=5*five[i-1];
    }
    for(i=0; i<25; i++){
        ans+=n/five[i];
    }
    printf("%lld",ans);
    return 0;
}

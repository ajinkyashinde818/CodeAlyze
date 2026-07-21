#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(void){
    long long n,k,i,j,ans=0,start,goal,stnum,glnum;
    long long place[200010]={},flag[200010]={},a[200010]={};
    scanf("%lld %lld\n",&n,&k);
    for(i=1; i<=n; i++){
        scanf("%lld",&a[i]);
    }
    place[0]=1;
    for(i=1; i<=n; i++){
        place[i]=a[place[i-1]];
    }
    for(i=0; i<=n; i++){
        flag[place[i]]++;
        if(flag[place[i]]==2){
            goal=place[i];
            glnum=i;
            goto NEXT;
        }
    }
    NEXT:;
    for(i=0; i<=n; i++){
        flag[i]=0;
    }
    for(i=0; i<=n; i++){
        flag[place[i]]++;
        if(flag[goal]==1){
            stnum=i;
            goto TUGI;
        }
    }
    TUGI:;
    if(k<=stnum){
        printf("%lld",place[k]);
        return 0;
    }
    ans=(k-stnum)%(glnum-stnum)+stnum;
    printf("%lld",place[ans]);
    return 0;
}

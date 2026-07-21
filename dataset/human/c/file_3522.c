#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ull unsigned long long

int main(){
    ull n,k,i,a[200002]={},machi=1,num=0,loop=0,check[200002]={},ans=0;
    scanf("%lld%lld",&n,&k);
    for (i=1; i<=n; i++) scanf("%lld",&a[i]);
    for (i=1; i<=k; i++) {
        num++;
        if (check[machi]!=0) break;
        check[machi]=i;
        machi=a[machi];
    }
    if (num==k) {
        printf("%lld",machi);
        return 0;
    }
    if (num==2) {
        printf("%d",1);
        return 0;
    }
    loop=num-check[machi];
    ans=(k-check[machi]+1)%loop;
    for (i=1; i<=ans; i++) {
        machi=a[machi];
    }
    printf("%lld",machi);
    return 0;
}

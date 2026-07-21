#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    long long int i, j, n, k, l, r, m, ans=0, po=0, popo;
    scanf("%lld %lld", &n, &k);
    long long int a[n];
    for(i=0; i<n; i++) scanf("%lld", &a[i]);
    l=1;
    r=1000000000;
    while(l!=r){
        po = 0;
        m = (l+r)/2;
        //printf("%lld %lld %lld\n", l, m, r);
        for(i=0; i<n; i++){
            
            if(a[i]>m) po += (a[i]-1)/m;
        }
        if(po<=k) r = m;
        else l = m+1;
    }
    printf("%lld", l);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    long long int n, i, j, ans=0, min=1000000001, nega=0, zero=0;
    scanf("%lld", &n);
    long long int a[n];
    for(i=0; i<n; i++) scanf("%lld", &a[i]);
    
    for(i=0; i<n; i++){
        if(abs(a[i])<min) min = abs(a[i]);
        ans += abs(a[i]);
        if(a[i] == 0) zero++;
        if(a[i]<0) nega++;
        nega = nega%2;
    }
    if(!zero && nega) ans = ans - min*2;
    printf("%lld", ans);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    long long int n, m, i, j, cnt=0;
    scanf("%lld %lld", &n, &m);
    long long int a[m+1], s[n+1];
    for(i=0; i<m; i++) scanf("%lld", &a[i]);
    s[0] = 1;
    a[m] = 0;
    for(i=1; i<=n; i++){
        if(i == a[cnt]){
            s[i] = 0;
            cnt++;
        }else{
            if(i==1) s[i] = 1;
            else{
                s[i] = (s[i-1] + s[i-2])%1000000007;
            }
        }
    }
    printf("%lld ", s[n]);

    
}

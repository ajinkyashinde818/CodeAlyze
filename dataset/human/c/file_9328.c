#include <stdio.h>
#include <string.h>

int main(void){
    long long int n,k,h[100000],i,j=0;
    scanf("%lld %lld",&n,&k);
    for (i=0; i<n; i++) {
        scanf("%lld",&h[i]);
        if (h[i]>=k) {
            j++;
        }
    }
    printf("%lld",j);
    return 0;
}

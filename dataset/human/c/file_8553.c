#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int asort(const void *A,const void *B){
    return *(long long*)A>*(long long*)B?1:0;
}

long long roundup(long long A,long long B){
    return (A+B-1)/B;
}

long long max(long long A,long long B){
    return A>B?A:B;
}

int main(void){
    int n;
    scanf("%d",&n);
    long long a[n];
    for (int i=0; i<n; i++){
        scanf("%lld",&a[i]);
    }
    qsort (a,n,sizeof(long long),asort);
    long long b[n];
    for (int i=0; i<n; i++){
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    for (int i=1; i<n-1; i++){
        if (b[i]<0){
            b[n-1]-=b[i];
        } else {
            b[0]-=b[i];
        }
    }
    printf("%lld\n",b[n-1]-b[0]);
    long long tmp=a[n-1];
    long long tmp2=a[0];
    for (int i=1; i<n-1; i++){
        if (a[i]<0){
            printf("%lld %lld\n",tmp,a[i]);
            tmp-=a[i];
        } else {
            printf("%lld %lld\n",tmp2,a[i]);
            tmp2-=a[i];
        }
    }
    printf("%lld %lld\n",tmp,tmp2);
    return 0;
}

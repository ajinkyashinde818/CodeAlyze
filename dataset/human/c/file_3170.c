#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
#include<tgmath.h>
#include<time.h>
#define ll long long
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define miin(a,b,c) min((a), min((b), (c)))
#define maax(a,b,c) max((a), max((b), (c)))

int k, n, a[222222], d=0;
main(){
    scanf("%d%d", &k, &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        if(i)d = max(d, a[i]-a[i-1]);
    }
    printf("%d\n", min(k-d, a[n-1]-a[0]));
    return 0;
}

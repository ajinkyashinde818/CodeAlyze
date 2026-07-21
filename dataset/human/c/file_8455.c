#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

typedef int32_t i32;
typedef int64_t i64;
typedef double f64;

void *const null=(void *)0;
i64 const llinf=4611686018427387903LL;
i64 const mod=1000000009LL;
f64 const pi=3.141592653589793;
f64 const rad=57.295779513082323;

#define CODE_

void swap(i64 *const x,i64 *const y){
    i64 t=*x;
    *x=*y;
    *y=t;
    return;
}

i32 main(void){
    i64 n,m;
    scanf("%lli%*c%lli%*c",&n,&m);
    i64 *a=(i64 *)calloc(n,sizeof(i64));
    for(i64 i=0LL;i<n;++i) scanf("%lli%*c",&a[i]);
    for(i64 k=1LL;k<=m;++k){
        for(i64 i=1LL;i<n;++i){
            i64 u=a[i-1LL],v=a[i];
            if(u-u/k*k>v-v/k*k) swap(&a[i-1LL],&a[i]);
        }
    }
    for(i64 i=0LL;i<n;++i) printf("%lli\n",a[i]);
    return 0;
}

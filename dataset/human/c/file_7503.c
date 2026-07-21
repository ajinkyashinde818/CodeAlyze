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

i32 main(void){
    i64 i=0LL,x;
    while(1){
        scanf("%lli",&x);
        if(x==0LL) break;
        ++i;
        printf("Case %lli: %lli\n",i,x);
    }
    return 0;
}

#include<assert.h>
#include<complex.h>
#include<ctype.h>
#include<errno.h>
#include<fenv.h>
#include<float.h>
#include<inttypes.h>
#include<iso646.h>
#include<limits.h>
#include<locale.h>
#include<math.h>
#include<setjmp.h>
#include<signal.h>
#include<stdalign.h>
#include<stdarg.h>
#include<stdatomic.h>
#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdnoreturn.h>
#include<string.h>
#include<tgmath.h>
#include<time.h>
#define SIZE 200000

int main(){
    int K,N;
    int A[SIZE];
    scanf("%d %d",&K,&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&A[i]);
    }
    int max = K - A[N-1] + A[0];
    for(int i = 1 ; i <= N-1 ; i++){
        if(max < A[i] -A[i-1]){
            max = A[i]-A[i-1];
        }
    }
    printf("%d",K-max);
    return 0;
}

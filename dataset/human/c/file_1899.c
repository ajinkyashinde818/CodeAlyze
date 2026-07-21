#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define input_i(x) scanf("%d", &x)
#define input_lli(x) scanf("%lld", &x)
#define input_s(x) scanf("%s", x)

#define BUFSIZE 1001

int main(int argc, char const *argv[]) {
    int N, i;
    input_i(N);
    int A[N], B[N], C[N - 1];
    for(i= 0; i < N; i++) {
        input_i(A[i]);
        A[i]--;
    }
    for(i= 0; i < N; i++) {
        input_i(B[i]);
    }
    for(i= 0; i < N - 1; i++) {
        input_i(C[i]);
    }
    int ans= 0, buf= -1;
    for(i= 0; i < N; i++) {
        ans+= B[A[i]];
        if(A[i] - buf == 1) ans+= C[buf];
        buf= A[i];
    }

    printf("%d\n", ans);

    return 0;
}

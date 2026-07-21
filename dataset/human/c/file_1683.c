#include <stdio.h>
#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    int A[N], B[N], C[N];
    int i=0;
    for(i=0;i<N;i++) {
        scanf("%d", &A[i]);
    }
    for(i=0;i<N;i++) {
        scanf("%d", &B[i]);
    }
    for(i=0;i<N-1;i++) {
        scanf("%d", &C[i]);
    }
    
    int prev = N;
    int sum = 0;
    for(i=0;i<N;i++) {
        sum += B[A[i] - 1];
        if (A[i] - prev == 1) {
            sum += C[prev - 1];
        }
        prev = A[i];
    }
    printf("%d", sum);
    return 0;
}

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    int eo = 1;
    int min = INT_MAX;
    int num = 0;
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
        if(A[i] == 0) eo = 0;
        if(A[i] < 0) eo *= -1;
        if(abs(A[i]) < min) {
            num = i;
            min = abs(A[i]);
        }
    }
    long sum = 0;
    if(eo >= 0) {
        for(int i=0; i<N; i++) {
            sum += abs(A[i]);
        }
    } else if(eo == -1) {
        for(int i=0; i<N; i++) {
            if(i==num) continue;
            sum += abs(A[i]);
        }
        sum -= abs(A[num]);
    }
    printf("%ld\n", sum);
    return 0;
}

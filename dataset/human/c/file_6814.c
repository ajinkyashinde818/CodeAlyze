#include <stdio.h>
#include <stdlib.h>

int cmp_int(void *a, void *b);

int main(){
    int N;
    long long sum = 0;
    scanf("%d", &N);

    int a[3 * N];
    for(int i = 0; i < 3 * N; i++){
        scanf("%d", &a[i]);
    }

    qsort(a, 3 * N, sizeof(int), cmp_int);

    for(int i = 0; i < N; i++){
        sum += a[2 * i + 1];
    }
    printf("%llu\n", sum);
    return 0;
}

int cmp_int(void *a, void *b){
    return *(int*)b - *(int*)a;
}

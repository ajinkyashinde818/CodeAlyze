#include<stdio.h>
#include<stdlib.h>

int a[200000];
int A[200000];

int comp(const void *a, const void *b){
    return A[*(int*)a] - A[*(int*)b];
}

typedef long long ll;

int main(void){
    int K;
    int N;
    scanf("%d %d", &K, &N);
    int i;
    for(i=0;i<N;i++){
        scanf("%d", &A[i]);
        a[i]=i;
    }

    qsort(a, N, sizeof(int), comp);
    int dist=A[a[1]]-A[a[0]];
    for(i=2;i<N;i++){
        if(dist < A[a[i]]-A[a[i-1]]){
            dist = A[a[i]]-A[a[i-1]];
        }
    }
    if(dist < A[a[0]]+K-A[a[N-1]]){
        dist = A[a[0]]+K-A[a[N-1]];
    }

    printf("%d", K-dist);
    return 0;
}

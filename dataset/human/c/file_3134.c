// AtCoder165 C

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <memory.h>
#include <malloc.h>
#include <stdlib.h>

// qsortで用いる比較用関数．*a<*bならaが先になる．
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int revcompare(const void* a, const void* b) {
    return *(int*)b- *(int*)a;
}


int main() {
    int i,j;
    int n;
    int k;
    int* a;
    int* a2a;
    int tmp,max = 0,max_i;
    int sum = 0;

    scanf("%d %d", &k, &n);
    a = (int*)malloc(sizeof(int) * n);
    a2a = (int*)malloc(sizeof(int) * n);

    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
        if(i >= 1){
            a2a[i-1] = a[i] - a[i-1];
            if(a2a[i-1] > max){
                max = a2a[i-1];
                max_i = i-1;
            }
        }
    }

    a2a[n-1] = a[0] + (k-a[n-1]);
    if(a2a[n-1] > max){
        max = a2a[n-1];
        max_i = n-1;
    }

    for(i=0;i<n;i++){
        if(i != max_i) sum += a2a[i];
    }
    
    printf("%d", sum);

    return 0;
}

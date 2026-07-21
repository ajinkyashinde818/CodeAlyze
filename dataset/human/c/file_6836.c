// 161-C Replacing Integer

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
    return -1 * (*(int*)a - *(int*)b);
}


int main() {

    int n, i, j,num_mem;
    int tmp, min;
    int* members;
    long long int sum;

    scanf("%d", &n);
    num_mem = 3 * n;
    members = (int*)malloc(sizeof(int) * num_mem);
    for (i = 0; i < num_mem; i++) {
        scanf("%d", &members[i]);
    }
    
    qsort(members, num_mem, sizeof(int), compare);


    sum = 0;
    for (i = 1; i < 2*n; i = i+2) {
        
        sum += members[i];
        //printf("i:%d sum:%lld", i, sum);

    }
    printf("%lld", sum);
    return 0;
}

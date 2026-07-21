#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define ARR_MAX 100000
#define BUF_SIZE (ARR_MAX*12)

int get_int2(int *a1, int *a2) {
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return -1;
  sscanf(line, "%d %d", a1, a2);
#else
#error
#endif
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array_half(int *arr, int size) {
#ifdef BUF_SIZE
    char line[BUF_SIZE];
    char *tmpbuf = line;
    int i;
    if(!fgets(line, BUF_SIZE, stdin)) return -1;
    for(i = 0; i < size; i++) {
        char *tmp = strtok(tmpbuf, " ");
        arr[i] = strtol(tmp, NULL, 10);
        arr[i] /= 2;
        tmpbuf = NULL;
    }
#else
#error
#endif
    return 0;
}

// assume that a <= b
uint64_t gcd(uint64_t a, uint64_t b) {
    if(a==0) return b;
    return gcd(b%a, a);
}

int desc(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int main(void) {
    int size, ulimit;
    int arr[ARR_MAX];
    get_int2(&size, &ulimit);
    fget_array_half(arr, size);
    int i;
    qsort(arr, size, sizeof(int), desc);

    uint64_t res = arr[0];
    int prev = arr[0];
    for(i = 1; i < size; i++) {
        int cur = arr[i];
        if(cur == prev) continue;
        // ensure that arr[i] <= res
        uint64_t g = gcd(cur, res);
        res = (res/g)*cur; // calc lcm
        prev = cur;
        // too big..
        if(res > ulimit) break;
    }
#ifdef DEBUG
    printf("ans: %llu(lcm)*(odd number)\n", res);
#endif
    if(res > ulimit) { printf("0\n"); return 0; }
    for(i = 0; i < size; i++) {
        int m = res / arr[i];
        // if even, No answer
        if(!(m%2)) { printf("0\n"); return 0; } 
    }
    uint64_t div = (uint64_t)ulimit/res;
    // answer should be integer
    printf("%d\n", (int)(div+1)/2);
    return 0;
}

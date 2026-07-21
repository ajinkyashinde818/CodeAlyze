#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

#define N_MAX (100)
#define P_MAX (100)
#define DP_ARRAY_SIZE (N_MAX * P_MAX / 32 + 1)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

int compare_f(const void* a, const void* b) {
    return *((int64_t*)a) < *((int64_t*)b) ? -1 : 1;
}

int compare_f2(const void* a, const void* b) {
    return *((uint64_t*)a) > * ((uint64_t*)b) ? -1 : 1;
}

static size_t comb(const size_t n, const size_t r) {
    size_t result = 1;

    for (size_t i = 0; i < r; i++) {
        result *= n - i;
        result /= i + 1;
    }

    return result;
}

static uint64_t combU64(const uint64_t n, const uint64_t r) {
    uint64_t result = 1;

    for (uint64_t i = 0; i < r; i++) {
        result *= n - i;
        result /= i + 1;
    }

    return result;
}

static uint64_t gcd(uint64_t m, uint64_t n)
{
    uint64_t temp;

    while (m % n != 0) {
        temp = n;
        n = m % n;
        m = temp;
    }

    return n;
}

static size_t gcdZu(size_t m, size_t n) {
    size_t temp;

    while (m % n != 0) {
        temp = n;
        n = m % n;
        m = temp;
    }

    return n;
}

static int64_t A[100000];

int main(void) {
    size_t N;

    scanf("%zu\n", &N);
    for (size_t i = 0; i < N; i++) {
        scanf("%"PRId64, &(A[i]));
        if (i < N - 1) {
            scanf(" ");
        }
    }

    size_t numMinus = 0;
    size_t minIdx = 0;

    for (size_t i = 0; i < N; i++) {
        if (A[i] < 0) {
            numMinus++;
        }

        if (ABS(A[i]) < ABS(A[minIdx])) {
            minIdx = i;
        }
    }

    const bool isMinusNumEven = (numMinus % 2 == 0);

    int64_t sum = 0;

    for (size_t i = 0; i < N; i++) {
        if (!(!isMinusNumEven && i == minIdx)) {
            sum += ABS(A[i]);
        }
        else {
            sum -= ABS(A[i]);
        }
    }

    printf("%"PRId64, sum);

    return 0;
}

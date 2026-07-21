#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

static const int MAX = 1e5;
static const long long INF = 1e9;
int N;
long A[MAX], s, r, cnt;

int main() {
    scanf("%d", &N);
    s = 0;
    r = INF;
    cnt = 0;

    for ( int i = 0; i < N; i++ ) {
        scanf("%ld", &A[i]);
        s += abs(A[i]);
        r = min(r, abs(A[i]));

        if ( A[i] < 0 ) {
            cnt = (cnt + 1) % 2;
        }
    }
    
    if ( cnt == 1 ) {
        s -= r * 2;
    }
    
    printf("%ld\n", s);
    return 0;
}

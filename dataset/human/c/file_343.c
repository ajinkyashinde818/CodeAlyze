#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n, r;
    scanf("%d%d", &n, &r);
    if (n < 10) {
        printf("%d\n", r + 100 * (10 - n));
    }else {
        printf("%d\n", r);
    }
}

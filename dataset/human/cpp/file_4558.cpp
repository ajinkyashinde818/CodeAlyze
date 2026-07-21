#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <complex>
using namespace std;

int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    if (n >= 10) {
        printf("%d\n", r);
    } else {
        printf("%d\n", r + (10-n) * 100);
    }
}

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <complex>
using namespace std;

long long int a[100005];

int main() {
    int n;
    scanf("%d", &n);
    long long int neg = 0;
    long long int sum = 0;
    long long int mi = 10000000000;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += abs(a[i]);
        mi = min(mi, abs(a[i]));
        if (a[i] < 0) {
            neg++;
        }
    }
    if (neg % 2 == 0) {
        printf("%lld\n", sum);
    } else {
        printf("%lld\n", sum - 2 * mi);
    }
}

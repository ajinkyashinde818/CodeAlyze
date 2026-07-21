#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <climits>

int main(void) {
    int n;
    scanf("%d", &n);
    long long s[n], sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        s[i] = sum + a;
        sum += a;
    }
    long long ans = LLONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        ans = std::min(llabs(s[i] - (sum - s[i])), ans);
    }
    printf("%lld\n", ans);
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int cnt = 0;
    long long sum = 0;
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
        cnt += a[i] < 0;
        sum += abs(a[i]);
        mn = min(abs(a[i]), mn);
    }
    if (cnt % 2 == 1) {
        sum -= mn * 2;
    }
    printf("%lld\n", sum);
    return 0;
}

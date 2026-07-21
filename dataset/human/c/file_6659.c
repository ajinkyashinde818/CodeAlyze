#include <stdio.h>
#define ll long long

ll maximumProfit(ll *arr, int n) {
    int i;
    ll min = 1000000001;
    ll maxp = -1000000001;

    for (i = 1; i < n; i++) {
        if (arr[i-1] < min) min = arr[i-1];
        if (arr[i] - min > maxp) maxp = arr[i] - min;
    }

    return maxp;
}

int main(void) {
    int n, idx;
    scanf("%d", &n);
    ll arr[n];

    for (idx = 0; idx < n; idx++) scanf("%lld", &arr[idx]);

    printf("%lld\n", maximumProfit(&arr, n));

    return 0;
}

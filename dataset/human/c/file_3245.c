#include <stdio.h>

int a[1000000];

int main() {

    int k, n;
    int i;
    int max;
    int temp;
    int ans;

    scanf("%d %d", &k, &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    max = k - a[n-1] + a[0];
    for(i = 0; i < n-1; i++) {
        temp = a[i+1] - a[i];
        if(max < temp) {
            max = temp;
        }
    }

    ans = k - max;
    printf("%d\n", ans);

    return 0;
}

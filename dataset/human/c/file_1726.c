#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n], b[n], c[n-1];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < n-1; i++) {
        scanf("%d", &c[i]);
    }

    int manzoku = 0;
    int tmp = -1;

    for(int i = 0; i < n; i++) {
        manzoku += b[a[i] - 1];
        if(tmp + 1 == a[i]) {
            manzoku += c[tmp - 1];
        }
        tmp = a[i];
    }

    printf("%d\n", manzoku);
    return 0;
}

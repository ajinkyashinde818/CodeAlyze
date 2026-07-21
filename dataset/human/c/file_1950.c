#include<stdio.h>

int main() {

    int n;
    int a[20], b[20], c[20];
    int satisfy;
    int before;
    scanf("%d", &n);

    int count = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &c[i]);
    }

    satisfy = 0;
    before = 100;
    for (int i = 0; i < n; i++) {
        satisfy = satisfy + b[a[i] - 1];
        if (before + 1 == a[i]) {
            satisfy = satisfy + c[before - 1];
        }
        before = a[i];
    }
    printf("%d", satisfy);
    return 0;
}

//
// Created by bytedance on 2020/4/10.
//


#include <bits/stdc++.h>
//#include <fstream>

using namespace std;
const int maxn = 2e5 + 5;

int a[maxn];
int b[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", b + i);
    }
    reverse(b, b + n);
    int l = 0, r = n - 1;
    while (l < n && a[l] != b[l]) l++;
    while (r >= 0 && a[r] != b[r]) r--;
    int tl = l, tr = r;
    for (int i = 0; i < tl && l <= r; i++) {
        if (b[i] != a[l] && a[i] != b[l]) {
            swap(b[i], b[l]);
            l++;
        } else {
            break;
        }
    }
    for (int i = n - 1; i > tr && l <= r; i--) {
        if (b[i] != a[r] && a[i] != b[r]) {
            swap(b[i], b[r]);
            r--;
        } 
        else {
            break;
        }
    }
    if (l <= r) {
        printf("No\n");
    } else {
        printf("Yes\n");
        for (int i = 0; i < n; i++) {
            printf("%d%c", b[i], i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}

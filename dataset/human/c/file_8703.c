#include <stdio.h>

int main() {
    int cnt = 0;

    int N;
    scanf("%d", &N);
    int a[N], b[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        b[i] = 0;
    }
    
    int x = 0;
    while (1) {
        if (x == 1) {
            break;
        }
        if (b[x]) {
            cnt = -1;
            break;
        }
        cnt++;
        b[x] = 1;
        x = a[x] - 1;
    }
    
    printf("%d\n", cnt);
    return 0;
}

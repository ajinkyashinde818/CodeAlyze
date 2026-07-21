// ABC065 B - Trained?
#include <stdio.h>

int main(void) {
    int N;  // 10^5
    scanf("%d", &N);
    int a[N + 1];
    int flag[100001] = { 0 };
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }
    int i = 1;
    int count = 0;
    while(1) {
        count++;
        int onButton = a[i];
        if (onButton == 2) {
            printf("%d\n", count);
            return 0;
        }
        if (flag[onButton] == 1) {
            printf("%d\n", -1);
            return 0;
        } else {
            flag[onButton] = 1;
        }
        i = onButton;
    }
}

#include<stdio.h>

int main() {
    int N = 0;
    scanf("%d", &N);
    int a[N - 1];
    for (int n = 0; n < N; n++) {
        scanf("%d", &a[n]);
    }
    int check = 1;
    int num = 0, count = 0;
    while(check) {
        num = a[num];
        count++;
        if (num == 2) {
            check = 0;
        }
        num--;
        if (count > N) {
            break;
        }
    }
    
    if (check) {
        printf("-1\n");
    } else {
        printf("%d\n", count);
    }

    return 0;
}

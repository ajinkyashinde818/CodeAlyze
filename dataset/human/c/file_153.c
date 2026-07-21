#include<stdio.h>
int main() {
    int n, i, ans[1000][1000],j,p,k;
    scanf("%d", &n);
    for (i = 2; i < 1000; i++) {
        if (n * 2 == i * (i - 1)) {
            p = 1;
            for (j = 0; j < i-1; j++) {
                for (k = j; k < i-1; k++)
                    ans[j][k] = p + k-j;
                for (k = j + 1; k < i; k++)
                    ans[k][j] = p + k - j - 1;
                p = p + k - j-1;
            }
            printf("Yes\n%d\n", i);
            for (j = 0; j < i; j++) {
                printf("%d", i - 1);
                for(k=0;k<i-1;k++)
                    printf(" %d", ans[j][k]);
                printf("\n");
            }
            return 0;
        }
    }
    printf("No\n");
    return 0;
}

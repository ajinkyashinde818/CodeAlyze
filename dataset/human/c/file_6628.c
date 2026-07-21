#include <stdio.h>

int main()
{
        int n;
        int R[200000];

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                scanf("%d", &R[i]);
        }

        int min = R[0];
        int max_profit = -1000000000;

        for (int i = 1; i < n; i++) {
                int temp;
                temp = R[i] - min;

                if (max_profit < temp) {
                        max_profit = temp;
                }

                if (min > R[i]) {
                        min = R[i];
                }
        }

        printf("%d\n", max_profit);

        return 0;
}

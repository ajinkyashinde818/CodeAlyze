#include <stdio.h>
#include <limits.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main(void)
{
    int n, max_profit, min_value;
    int R[2000000];

    /* 値の受け取り */
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &R[i]);

    /* 初期化 */
    max_profit = INT_MIN;
    min_value = R[0];

    /* 最大利益の計算 */
    for (int j = 1; j < n; j++)
    {
        max_profit = max(max_profit, R[j] - min_value);
        min_value = min(min_value, R[j]);
    }

    /* 出力 */
    printf("%d\n", max_profit);

    return 0;
}

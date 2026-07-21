#include <stdio.h>

int main(void)
{
    int n;
    int p[128];
    int i, j;
    int score;
    scanf("%d", &n);

    for (i = 0; i < n; ++i) scanf("%d", p + i);

    for (i = 0; i < n - 1; ++i){
        for (j = 0; j < n - i - 1; ++j){
            if (p[j] < p[j + 1]){
                int t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }

    score = 0;
    for (i = 0; i < n; ++i){
        if (i + 1 <= p[i]) score = i + 1;
    }
    printf("%d\n", score);

    return 0;
}

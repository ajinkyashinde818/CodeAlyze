#include <stdio.h>
#define MAX_N 100000

int a[MAX_N] = {0};
bool lighten[MAX_N] = {false};

int dfs(void)
{
    int i = 0, cnt = 0;
    for (;;) {
        if (lighten[1]) return cnt;
        i = a[i] - 1;
        if (lighten[i]) return -1;
        lighten[i] = true;
        cnt++;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    lighten[0] = true;
    printf("%d\n", dfs());
}

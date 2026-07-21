#include <stdio.h>

int main(void)
{
    int flag[3] = { 0, 0, 0 };
    flag[getchar() - 'a'] = 1;
    flag[getchar() - 'a'] = 1;
    flag[getchar() - 'a'] = 1;
    if (flag[0] && flag[1] && flag[2]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

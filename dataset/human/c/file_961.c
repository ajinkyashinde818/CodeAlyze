#include <stdio.h>

typedef struct
{
    char e;
    int y;
} year;

year ytoj(int y)
{
}

int main(void)
{
    int e, y;
    int ans;

    scanf("%d %d", &e, &y);
    switch (e){
    case 0:
        if (y < 1912){
            putchar('M');
            ans = y - 1868 + 1;
        }
        else if (y < 1926){
            putchar('T');
            ans = y - 1912 + 1;
        }
        else if (y < 1989){
            putchar('S');
            ans = y - 1926 + 1;
        }
        else {
            putchar('H');
            ans = y - 1989 + 1;
        }
        break;
    case 1:
        ans = y + 1868 - 1;
        break;
    case 2:
        ans = y + 1912 - 1;
        break;
    case 3:
        ans = y + 1926 - 1;
        break;
    case 4:
        ans = y + 1989 - 1;
        break;
    }
    printf("%d\n", ans);

    return 0;
}

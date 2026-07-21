#include<stdio.h>
#ifdef DEBUG
#include<conio.h>
#endif // DEBUG

int main () {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif // DEBUG

    int num;
    scanf("%d", &num);
    int cnt = 1;
    while (num != 0)
    {
        printf("Case %d: %d\n", cnt++, num);
        scanf("%d", &num);
    }

#ifdef DEBUG
    getch();
#endif // DEBUG
    return 0;
}

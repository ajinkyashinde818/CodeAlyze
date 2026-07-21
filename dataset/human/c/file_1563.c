#include <stdio.h>

int main(void)
{
    char ch[6] = "ABCDEF";
    char a, b;
    int n, m;

    scanf("%c %c", &a, &b);
    for (int i = 0; i < 6; i++){
        if (a == ch[i])
        n = i;
        if (b == ch[i])
        m = i;
    }

    if (n > m)
        printf(">");
    else if (n < m)
        printf("<");
    else if (n == m)
        printf("=");

    return 0;
}

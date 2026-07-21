#include <stdio.h>

int convrt(char c)
{
    switch (c) {
        case 'A' : return 10;
        case 'B' : return 11;
        case 'C' : return 12;
        case 'D' : return 13;
        case 'E' : return 14;
        case 'F' : return 15;
    }
}

int main(void)
{
    char x, y;
    scanf("%c %c", &x, &y);
    int a, b;
    a = convrt(x);
    b = convrt(y);
    if (a < b)
        puts("<");
    else if (a == b)
        puts("=");
    else
        puts(">");
    return 0;
}

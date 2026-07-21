#include <stdio.h>

int main(void)
{
    char x, y;
    int ix, iy;
    scanf("%c %c", &x, &y);
    switch (x)
    {
    case 'A':
        ix = 10;
        break;
    case 'B':
        ix = 11;
        break;
    case 'C':
        ix = 12;
        break;
    case 'D':
        ix = 13;
        break;
    case 'E':
        ix = 14;
        break;
    case 'F':
        ix = 15;
        break;
    default:
        break;
    }

    switch (y)
    {
    case 'A':
        iy = 10;
        break;
    case 'B':
        iy = 11;
        break;
    case 'C':
        iy = 12;
        break;
    case 'D':
        iy = 13;
        break;
    case 'E':
        iy = 14;
        break;
    case 'F':
        iy = 15;
        break;
    default:
        break;
    }
    if (ix > iy)
        printf(">");
    else if (ix < iy)
        printf("<");
    else
        printf("=");

    return (0);
}

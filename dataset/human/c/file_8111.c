#include <stdio.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main(int argc, char **argv)
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d\n", MAX(a*b, c*d));
    return 0;
}

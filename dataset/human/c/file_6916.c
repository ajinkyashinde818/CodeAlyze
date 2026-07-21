#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>

int main(int argc, char **argv)
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf(n == m ? "Yes" : "No");
    return EXIT_SUCCESS;
}

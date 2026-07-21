#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(type, x, y)  do {type t = x; x = y; y = t;} while (0)

void quick(int a[], int left, int right)
{
    int pl = left;
    int pr = right;
    int x = a[(pl + pr) / 2];
    do {
        while (a[pl] < x) ++pl;
        while (a[pr] > x) --pr;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            ++pl;
            --pr;
        }
    } while (pl <= pr);
    if (left < pr) quick(a, left, pr);
    if (pl < right) quick(a, pl, right);
}

int main(void)
{
    char a[5];
    scanf("%s", a);

    int sum = a[0] + a[1] + a[2];
    if (sum == 294) printf("%s\n", "Yes");
    else printf("%s\n", "No");
    return 0;
}

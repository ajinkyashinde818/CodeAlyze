#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0, b = 0, k = 0, res = 0, count = 0, div = 0;

    scanf("%d %d %d", &a, &b, &k);

    if (a % b == 0) {
        for (int i = b; i >= 1; i--) {
            if (count == k) {
                break;
            }
            if ((a % i) == 0 && (b % i) == 0) {
                count++;
                res = i;
            }
        }
        printf("%d\n", res);
    } else if (b % a == 0) {
        for (int i = a; i >= 1; i--) {
            if (count == k) {
                break;
            }
            if ((a % i) == 0 && (b % i) == 0) {
                count++;
                res = i;
            }
        }
        printf("%d\n", res);
    } else {
        for (int i = 100; i >= 1; i--) {
            if (count == k) {
                break;
            }
            if ((a % i) == 0 && (b % i) == 0) {
                count++;
                res = i;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

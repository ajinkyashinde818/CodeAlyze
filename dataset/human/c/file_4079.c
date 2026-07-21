#include <stdio.h>

int gcd(int x, int y) {
    int r;
    while ((r = x % y) != 0) {
        x = y;
        y = r;
    }
    return y;
}

int main() {
	int a, b, k;
	scanf("%d%d%d", &a, &b, &k);
    int GCD = gcd(a, b);
    for (int i = 1; i <= GCD; i++) {
        if (GCD % i == 0) {
            k--;
            if (k == 0) {
                printf("%d\n", GCD / i);
                return 0;
            }
        }
    }
	return 0;
}

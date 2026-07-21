#include <stdio.h>
int main(void) {
    int r, g, b, n;
    int sum, temp1, temp2, temp;
    int ans = 0;
    int i, j, k;
    scanf("%d %d %d %d", &r, &g, &b, &n);
    if (r > g) {
        temp = r;
        r = g;
        g = temp;
    }
    if (r > b) {
        temp = r;
        r = b;
        b = temp;
    }
    if (g > b) {
        temp = g;
        g = b;
        b = temp;
    }

    sum = 0;

    for (; 1; sum += r) {
        if (sum == n) {
            ans++;
            break;
        }
        if (sum > n) {
            break;
        }
        temp1 = sum;
        for (; 1; sum += g) {
            if (sum == n) {
                ans++;
                sum = temp1;
                break;
            }
            if (sum > n) {
                sum = temp1;
                break;
            }
            temp2 = sum;
            if ((n - sum) % b == 0) {
                ans++;
            }
            /*for (; 1; sum += b) {
                if (sum == n) {
                    ans++;
                    sum = temp2;
                    break;
                }
                if (sum > n) {
                    sum = temp2;
                    break;
                }
            }*/
        }
    }
    printf("%d\n", ans);
    return 0;
}

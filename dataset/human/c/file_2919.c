#include <stdio.h>

int main() {

    int k, s;
    scanf("%d %d", &k, &s);

    int cnt = 0;
    for (int x = 0; x <= k; x++) {

        if (x > s) {
            break;
        }
        for (int y = 0; y <= k; y++) {

            int z = s - x - y;
            //printf("%d %d %d\n", x, y, z);
            if (z < 0) {
                break;
            }
            if (z <= k) {
                cnt++;
            }

        }
    }

    printf("%d", cnt);



    return 0;
}

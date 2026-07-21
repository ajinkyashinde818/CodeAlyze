#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char an[n+1][50+1];
    char bm[m+1][50+1];
    for (int i = 1; i <= n; i++) {
        scanf("%s", &(an[i][1]));
    }
    for (int i = 1; i <= m; i++) {
        scanf("%s", &(bm[i][1]));
    }

    for (int i = 1; i <= n-(m-1); i++) {
        for (int j = 1; j <= n-(m-1); j++) {
            int found = 1;
            for (int x = 1; x <= m; x++) {
                for (int y = 1; y <= m; y++) {
                    if (bm[x][y] != an[x+i-1][y+j-1]) {
                        found = -1;
                        break;
                    }
                }
            }
            if (found == 1) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");

    return 0;
}

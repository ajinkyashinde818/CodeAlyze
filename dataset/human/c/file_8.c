#include <stdio.h>

int main() {
    int R, G, B, N, s, c=0;

    scanf("%d %d %d %d", &R, &G, &B, &N);
    int i = 0;
    while(1) {
        s = R * i;
        if (s >= N) {
            if (s == N) c++;
            break;
        }

        int j = 0;
        while(1) {
            s = R*i + G*j;
            if (s >= N) {
                if (s == N) c++;
                break;
            }

            int k = 0;
            while(1) {
                s = R*i + G*j + B*k;
                if (s >= N) {
                    if (s == N) c++;
                break;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    printf("%d", c);
    return 0;
}

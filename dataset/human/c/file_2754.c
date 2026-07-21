#include <stdio.h>

int min(int x, int y) {
    if (x <= y)
        return x;
    return y;
}

int main() {
    int K, S;
    int cnt = 0;
    scanf("%d %d", &K, &S);

    for (int X = 0; X <= min(K, S); X++) {
        for (int Y = 0; Y <= min(K, S); Y++) {
            if (S - X - Y >= 0 && S - X - Y <= min(S - X - Y, K))
                cnt ++;
        }
    }
    printf("%d\n", cnt);
}

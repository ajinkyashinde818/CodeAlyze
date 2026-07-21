#include <stdio.h>

int main(void)
{
    int K, S;
    int X, Y;
    int diff;
    int cnt;

    scanf("%d %d", &K, &S);

    cnt = 0;
    for (X = 0; X <= K; ++X){
        for (Y = 0; Y <= K; ++Y){
            diff = S - X - Y;

            if (0 <= diff && diff <= K){
                ++cnt;
            }
        }
    }

    printf("%d\n", cnt);

    return (0);
}

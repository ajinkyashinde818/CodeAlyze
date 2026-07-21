#include <bits/stdc++.h>
using namespace std;

int R, G, B, N;
int res;

int main()
{
    scanf("%d %d %d %d", &R, &G, &B, &N);
    for (int r = 0; r <= N; r++)
        for (int g = 0; g <= N; g++) {
            int b = N - r * R - g * G;
            if (b >= 0 && b % B == 0) res++;
        }
    printf("%d\n", res);
    return 0;
}

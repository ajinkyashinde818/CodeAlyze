# include <stdio.h>
# include <string.h>

void swap(int *nx, int *ny)
{
    int temp = *nx;
    *nx = *ny;
    *ny = temp;
}


void sort3(int *n1, int *n2, int *n3)
{
    if (*n1 > *n2) swap(n1, n2);
    if (*n2 > *n3) swap(n2, n3);
    if (*n1 > *n2) swap(n1, n2);
}


int main()
{
    int R, G, B, N;
    scanf("%d%d%d%d", &R, &G, &B, &N);
    sort3(&R, &G, &B);

    int r, g;
    int ans = 0;
    for (int i = 0; i < N/R + 1; ++i)
    {
        r = i;
        if (r*R > N) break;
        for (int j = 0; j < (N-r*R)/G + 1; ++j)
        {
            g = j;
            if (r*R + g*G > N) break;
            int rem = N - r*R - g*G;
            if (rem % B == 0) ans++;
        }
    }

    printf("%d\n", ans);

}

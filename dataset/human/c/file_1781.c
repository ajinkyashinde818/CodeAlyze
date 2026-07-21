#include <stdio.h>

int main()
{
        int N;
        int a[100];
        int b[100];
        int c[100];
        int out = 0;

        scanf("%d", &N);

        for (int i = 0; i < N; i++)     scanf("%d", &a[i]);
        for (int i = 0; i < N; i++)     scanf("%d", &b[i]);
        for (int i = 0; i < N-1; i++)   scanf("%d", &c[i]);

        for (int i = 0; i < N; i++) {
                out += b[a[i]-1];
                if (a[i]-1 == a[i-1]) {
                        out += c[a[i-1]-1];
                }
        }

        printf("%d\n", out);

        return 0;
}

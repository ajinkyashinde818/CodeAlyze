#include <stdio.h>
int main()
{
    int N, D, X;
    scanf("%d", &N);
    scanf("%d %d", &D, &X);

    int A[100];
    for (int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }

    int ans = 0;
    for (int i=0; i<N; i++) {
        int tmp = 0;
        for (int j=1; j<=D; j+=A[i]) tmp++;
        ans += tmp;
    }

    ans += X;

    printf("%d\n", ans);
}

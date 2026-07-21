#include <stdio.h>

#define MAX(a,b) ((a > b) ? a : b)

int main ()
{
    int A,B,K;
    scanf("%d%d%d", &A, &B, &K);    

    int max_num = MAX(A, B);
    int div,ans;
    int cnt = 0;
    for (div = max_num; div >= 0; div--) {
        if (A % div == 0 && B % div == 0) {
            cnt++;
        }
        if (cnt == K) {
            ans = div;
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}

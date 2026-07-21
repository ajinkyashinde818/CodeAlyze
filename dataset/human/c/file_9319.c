#include <stdio.h>

int main( void ) {
    int N, K;
    int h[100000];
    int i, ans;

    scanf("%d %d", &N, &K);
    for (i=0;i<N;++i) {
        scanf("%d", &h[i]);
    }

    ans = 0;
    for (i=0;i<N;++i) {
        if ( h[i] >= K ) {
            ans++;
        }
    }

    printf("%d", ans);

    return 0;
}

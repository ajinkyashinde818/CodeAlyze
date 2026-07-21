#include <stdio.h>

int minimum(int, int);

int main(){
    int n, m, a, b[100000], i, j;

    scanf("%d %d", &n, &m);

    for(i=0; i<=n; i++){
        b[i] = -1;
    }

    for(i=0; i<m; i++){
        scanf("%d", &a);
        b[a] = 0;
    }

    b[0] = 1;

    if(b[1] < 0)
        b[1] = 1;

    for(i=2; i<=n; i++){
        if(b[i] < 0)
            b[i] = (b[i-1] + b[i-2]) % 1000000007;
    }

    printf("%d\n", b[n]);
    return 0;
}

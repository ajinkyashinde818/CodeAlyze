#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d%d\n", &N, &K);
    int res = 0;
    for(int ni=0; ni<N; ni++){
        int h;
        scanf("%d", &h);
        if(h >= K){
            res ++;
        }
    }
    printf("%d\n", res);
    return 0;
}

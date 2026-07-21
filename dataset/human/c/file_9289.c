#include <stdio.h>

int main(void){
    int n, k, cnt = 0;
    int h[100001];

    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%d", h + i);
        if(h[i] >= k){
            cnt++;
        }
    }
    printf("%d\n", cnt);
    
    return 0;
}

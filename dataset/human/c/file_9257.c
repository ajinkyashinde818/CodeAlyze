#include <stdio.h>

int main(){
    int n, k;
    int h[10000000];
    int ans = 0;
    int i;

    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &h[i]);
    }

    for(i = 0; i < n; i++){
        if(h[i] >= k){
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}

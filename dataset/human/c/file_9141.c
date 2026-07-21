#include <stdio.h>
int main(void) {
    int a[200000];
    int n, k;
    int ans=0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i <n ; ++i) {
        scanf("%d", &a[i]);
        if(a[i] >= k ){
            ans++;
        }
        }
    printf("%d", ans);
}

#include <stdio.h>
int main(void){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int ans = 0;
    int i = 1;
    while (i != 2){
        i = a[i-1];
        ans++;
        if (ans >= n){
            ans = -1;
            break;
        }
    }
    printf("%d\n", ans);

    return 0;
}

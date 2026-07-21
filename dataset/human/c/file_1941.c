#include <stdio.h>

int a[110], b[110], c[110];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]); a[i]--;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < n - 1; i++){
        scanf("%d", &c[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += b[a[i]];
        if(i > 0 && a[i] == a[i - 1] + 1) ans += c[a[i - 1]];
    }
    printf("%d\n", ans);
}

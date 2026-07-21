#include <stdio.h>
#include <string.h>

int main(){
    char a[51][51], b[51][51];
    int n, m, i, j, k, l;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++) scanf("%s", a[i]);
    for(i = 0; i < m; i++) scanf("%s", b[i]);
    int ans = 0;
    for(i = 0; i < n - m + 1; i++){
        for(j = 0; j < n - m + 1; j++){
            for(k = 0; k < m; k++){
                for(l = 0; l < m; l++){
                    if(a[i + k][j + l] != b[k][l]){
                        k = m;
                        break;
                    }
                    if(k == m - 1 && l == m - 1) ans = 1;
                }
            }
        }
    }
    if(ans) printf("Yes\n");
    else printf("No\n");
    return 0;
}

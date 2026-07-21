#include <stdio.h>
#define REP(i, a, b) for(int i = a; i < b; i++)

int main(void)
{
    int n,m;
    char a[100][100];
    char b[100][100];
    int s=0,q=0;
    
    scanf("%d %d",&n,&m);
    
    REP(i, 0, n) {
        scanf("%s",a[i]);
    }
    REP(i, 0, m) {
        scanf("%s",b[i]);
    }
    for(int i = 0; i <= n - m; i++){
        for(int l = 0; l <= n - m; l++){
            s = 0;
            for(int j = 0; j < m; j++){
                for(int k = 0; k < m; k++){
                    if (a[k + i][j + l] == b[k][j]) {
                        s++;
                    }
                }
            }
            if (s == m * m) {
                q=1; break;
            }
        }
    }
    if (q == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

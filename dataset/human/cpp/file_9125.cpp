#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,m;
    scanf("%d%d", &n, &m);
    bool f=false;
    char gn[n][n];
    char gm[m][m];
    for (int i=0; i<n; i++) {
        scanf("%s", &gn[i]);
    }
    for (int i=0; i<m; i++) {
        scanf("%s", &gm[i]);
    }
    for (int i=0; i<=n-m; i++) {
        for (int j=0; j<=n-m; j++) {
            bool mt=true;
            for (int k=0; k<m; k++) {
                for (int l=0; l<m; l++) {
                    if (gn[i+k][j+l]!=gm[k][l]) {
                        mt=false;
                        break;
                    }
                }
                if (!mt) break;
            }
            f |= mt;
        }
    }
    printf("%s\n", f ? "Yes":"No");
}

#include <stdio.h>
#include <string.h>
int a[11][6], b[11][6];

int main(void)
{
    int n, m=5;
    while (scanf("%d", &n), n) {
        int i, j, k, l, res, changed;
        memset(a, -1, sizeof(a));
        for(i=0;i<n;++i) for(j=0;j<m;++j) scanf("%d", &b[i][j]);

        res=0;
        changed=1;
        while (changed) {
            memcpy(a, b, sizeof(a));
            changed=0;
            for(i=n-1;i>=0;--i) {
                for(j=m;j>=3;--j) {
                    for(k=0;k<=m-j;++k) {
                        int t=a[i][k], ok=t>0;
                        for(l=1;l<j;++l) ok=ok&(t==a[i][k+l]);
                        if (ok) {
                            for(l=0;l<j;++l) a[i][k+l]=0;
                            res+=t*j;
                            changed=1;
                            goto NEXTROW;
                        }
                    }
                }
NEXTROW:;
            }
            memset(b, 0, sizeof(b));
            for(j=0;j<m;++j)
                for(i=k=n-1;i>=0;--i)
                    if (a[i][j]) b[k--][j]=a[i][j];
        }
        printf("%d\n", res);
    }
    return 0;
}

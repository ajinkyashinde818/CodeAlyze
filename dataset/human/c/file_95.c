#include <stdio.h>
int main(void)
{
    int r, g, b, n, i=0, k=0, j=0, cnt=0;
    scanf("%d%d%d%d", &r, &g, &b, &n);
    
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            k=(n-(i*r)-(j*g))/b;
            if(i*r+j*g+k*b==n && (n-(i*r)-(j*g))%b==0 && k>=0) cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}

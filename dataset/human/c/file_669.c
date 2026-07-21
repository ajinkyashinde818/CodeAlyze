#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[50][51],b[50][51];
    int n,m,f,i,j,k,l;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",a[i]);
    for(i=0;i<m;i++)scanf("%s",b[i]);
    for(i=0;i<=n-m;i++){
        for(j=0;j<=n-m;j++){
            f=0;
            for(k=i;k<i+m;k++)for(l=j;l<j+m;l++)if(a[k][l]!=b[k-i][l-j])f=1;
            if(f==0){
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}

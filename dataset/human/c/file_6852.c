#include <stdio.h>
int main(){
    int n,top,a[110][110],temp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    for(int i=0;i<=n;i++)a[i][0]=a[0][i]=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
    top=a[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<i;k++){
                for(int m=0;m<j;m++){
                    temp=a[i][j]-a[k][j]-a[i][m]+a[k][m];
                    if(temp>top)top=temp;
                }
            }
        }
    }
    printf("%d\n",top);
}

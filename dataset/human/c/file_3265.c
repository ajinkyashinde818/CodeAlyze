#include <stdio.h>
int main(void){
    int k,n,a[1000000],ans,x=0;
    // 入力
    scanf("%d%d",&k,&n);
    for (int i=1; i<=n ;i++){
        scanf("%d",&a[i]);
    }
    // 家の間の最長距離xを求める
    for (int j=1; j<=n-1 ;j++){
        if (x < a[j+1] - a[j]){
            x = a[j+1] - a[j];
        }
    }
    if (x < a[1] + k - a[n]){
        x = a[1] + k - a[n];
    }
    // 解
    ans = k - x;
    printf("%d",ans);
}

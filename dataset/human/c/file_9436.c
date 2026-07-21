#include<stdio.h>
 
main(){
    int n, d, x;
    int a[101];
    int i;
    int t;
 
    // 整数の入力
    scanf("%d", &n);
    // スペース区切りの整数の入力
    scanf("%d %d",&d, &x);
 
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
 
    t=x;
    for(i = 1; i <= n; i++){
        t += 1 + (d - 1) / a[i];
    }
    
    // 出力
    printf("%d\n", t);
}

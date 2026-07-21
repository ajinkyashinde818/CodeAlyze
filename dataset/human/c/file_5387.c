#include <stdio.h>

int min(int a,int b){
    if(a>b){
        return b;
    }
    return a;
}

int main(void){
    int n,m,x;
    scanf("%d %d %d", &n,&m,&x);
    int c[12];
    int a[12][12];
    int ans = 100000007;
    for(int i = 0; i<n; i++){
        scanf("%d",&c[i]);
        for(int j = 0; j<m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int bit = 0; bit<(1<<n); bit++){
        int s[12];
        int t = 0;
        for(int i = 0; i<m; i++){
            s[i] = 0;
        }
        for(int i = 0; i<n; i++){
            if(bit & (1<<i)){
                t += c[i];
                for(int j = 0; j<m; j++){
                    s[j] += a[i][j];
                }
            }
        }
        int flag = 1;
        for(int i = 0; i<m; i++){
            if(s[i]<x){
                flag = 0;
            }
        }
        if(flag){
            ans = min(ans,t);
        }
    }
    if(ans==100000007){
        printf("%d\n",-1);
        return 0;
    }
    printf("%d\n", ans);
    return 0;
}

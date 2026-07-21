#include<stdio.h>

int main(void){
    int n;
    int ans = 0;
    scanf("%d",&n);
    int a[n],b[n],c[n - 1];
    for(int i = 0;i < n;i++)scanf("%d",&a[i]);
    for(int i = 0;i < n;i++)scanf("%d",&b[i]);
    for(int i = 0;i < n - 1;i++)scanf("%d",&c[i]);
    for(int i = 0;i < n - 1;i++){
        ans += b[a[i] - 1];
        if(a[i+1] == a[i] + 1){
            ans += c[a[i] - 1];
        }
    }
    ans += b[a[n-1] - 1];
    printf("%d",ans);
    return 0;
}

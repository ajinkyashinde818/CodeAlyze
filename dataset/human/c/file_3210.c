#include <stdio.h>
int max(int p,int q){
    if(p>q) return p;
    else return q;
}
int main(void){
    int k,n,i;
    scanf("%d%d",&k,&n);
    int a[n];
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    int ans = k+a[0]-a[n-1];
    for(i=0;i<n-1;i++) ans = max(ans,a[i+1]-a[i]);
    printf("%d",k-ans);
    return 0;
}

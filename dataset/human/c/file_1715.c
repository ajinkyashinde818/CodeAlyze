#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    int a[n+1],b[n+1],c[n+1];
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<n;i++)
        scanf("%d",&c[i]);
    int ans=b[a[1]];
    for(i=1;i<n;i++){
        if(a[i+1]==1+a[i])
            ans+=c[a[i]];
        ans+=b[a[i+1]];
    }
    printf("%d\n",ans);
    return 0;
}

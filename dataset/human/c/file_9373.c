#include <stdio.h>

int main(){
    int n,d,x;
    int a[1010];
    scanf("%d%d%d",&n,&d,&x);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int ans=x;
    for(int i=0;i<n;i++){
        ans+=(d+a[i]-1)/a[i];
    }
    printf("%d\n",ans);
}

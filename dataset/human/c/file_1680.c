#include <stdio.h>

int main(){
    int n;
    int ans=0;
    int a[20];
    int b[20];
    int c[20];
    int i,x;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(i=1;i<n;i++){
        scanf("%d",&c[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]-1==a[i-1]){
            ans+=c[a[i]-1];
        }
        x=a[i];
        ans+=b[(a[i]-1)];
    }
    printf("%d",ans);
}

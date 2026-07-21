#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n],b[n],c[n-1];
    for(int d=0;d<n;d++){scanf("%d",&a[d]);}
    for(int e=0;e<n;e++){scanf("%d",&b[e]);}
    for(int f=0;f<n-1;f++){scanf("%d",&c[f]);}
    int ans;
    ans=0;
    for(int i=0;i<n;i++){
        ans+=b[a[i]-1];
        if(a[i]+1==a[i+1]){ans+=c[a[i]-1];}
    }
    printf("%d\n",ans);
    return 0;
}

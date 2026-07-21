#include <stdio.h>

int main(){
     int n;
     scanf("%d",&n);
     int a[n],b[n],c[n-1];

    for (int i = 0; i <n ; ++i) {
        scanf("%d",&a[i]);
    }

    for (int i = 0; i <n ; ++i) {
        scanf("%d",&b[i]);
    }

    for (int i = 0; i <n-1 ; ++i) {
        scanf("%d",&c[i]);
    }
    int ans=0;
    for (int j = 0; j <n ; ++j) {
        ans+=b[a[j]-1];
        if(j>0)
        if(a[j]==a[j-1]+1)
            ans+=c[a[j-1]-1];
    }
    printf("%d",ans);
}

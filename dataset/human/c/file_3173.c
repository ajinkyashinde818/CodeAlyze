#include <stdio.h>
#include <stdlib.h>

int main(){
    int k,n;
    int a[200000];
    int ans = 0;
    int maxdis = 0;
    int dep = 0;
    scanf("%d %d",&k,&n);
    for(int i = 0;i < n;i++){
        a[i] = -1;
        scanf("%d",&a[i]);
    }
    for(int i = 0;i < n - 1 && a[i + 1] > 0;i++){
        if(a[i + 1] - a[i] > maxdis){
             maxdis = a[i + 1] - a[i];
             dep = i;
        }
    }
    if(k - a[n - 1] > maxdis){
         maxdis = k - a[n];
         dep = n;
    }
    if(dep == 0 || dep == n){
        ans = a[n - 1] - a[0];
    }else{
        ans = k - (a[dep + 1] - a[dep]);
    }
    printf("%d",ans);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int max(int a, int b) { return a > b ? a : b; }
int main(void){
    int i,k,n,tmp,ans=0,a[200000],d[200000];
    scanf("%d %d\n",&k,&n);
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(i=0; i<n-1; i++){
        d[i]=a[i+1]-a[i];
    }
    d[n-1]=k-(a[n-1]-a[0]);
    for(i=0; i<n; i++){
        tmp=max(tmp,d[i]);
    }
    ans=k-tmp;
    printf("%d",ans);
    return 0;
}

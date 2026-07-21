#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
int compare(const void *a,const void *b){
    if(*(int *)a>*(int *)b)return -1;
    return 1;
}
int main(int argc, const char * argv[]) {
    int n,k;
    scanf("%d%d",&k,&n);
    int a[n],d[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i==0)continue;
        d[i-1]=a[i]-a[i-1];
    }
    d[n-1]=k-a[n-1]+a[0];
    qsort(d,n,sizeof(int),compare);
    printf("%d",k-d[0]);
    return 0;
}

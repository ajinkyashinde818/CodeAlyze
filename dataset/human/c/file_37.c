#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b){return *(int*)b-*(int*)a;}
int main(){
    int a[3],n,i,j,r=0;
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&n);
    qsort(a,3,4,compare);
    for(i=0;i<=n/a[0];i++){
        for(j=0;j<=(n-i*a[0])/a[1];j++){
            r+=(n-i*a[0]-j*a[1])%a[2]==0;
        }
    }
    printf("%d",r);
    return 0;
}

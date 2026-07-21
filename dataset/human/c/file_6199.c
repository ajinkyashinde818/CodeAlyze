#include<stdio.h>
#define MAX 200000
int main(){
    int n,R[MAX],i,minv,maxv;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&R[i]);
    }
    minv=R[0];
    maxv=R[1]-R[0];
    for(i=1; i<=n-1; i++){
        if(maxv<R[i]-minv)maxv=R[i]-minv;
        if(minv>R[i])minv=R[i];
    }
    printf("%d\n",maxv);
    return 0;
}

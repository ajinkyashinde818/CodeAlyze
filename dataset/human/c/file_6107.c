#include<stdio.h>
#define MAX 200000
int min(int a,int b){
    if(a>b)a=b;
    return a;
}
int max(int a,int b){
    if(a<b)a=b;
    return a;
}
int main(void){
    int i,n,R[MAX];
    int maxx=-2000000000;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        scanf("%d\n",&R[i]);
    }
int minx=R[0];
    for(i=1;i<n;i++){
        maxx=max(maxx,R[i]-minx);
        minx=min(minx,R[i]);
    }
    // for(i=0;i<n-1;i++){
    //     for(j=i+1;j<n;j++){
    //         if(v<R[j]-R[i]){
    //             v=R[j]-R[i];
    //         }
    //     }
    // }
    printf("%d\n",maxx);
    return 0;
}

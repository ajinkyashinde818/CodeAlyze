#include <stdio.h>
#define MAX_NUM 200000
int main (void){
    int R[MAX_NUM];
    int ans;
    int i,n;
    int R_min;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&R[i]);
    }
    R_min=R[0];
    ans = R[1]-R[0];
    for(i=1;i<n;i++){
        if(R[i]-R_min>ans) ans=R[i]-R_min;
        if(R_min>R[i]) R_min=R[i];
    }
    printf("%d\n",ans);
    return 0;
}

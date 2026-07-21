#include<stdio.h>

int main(void){
    int n,r[300000],i;
    int maxv=-999999999,minv;
    scanf("%d %d",&n,&r[0]);
    minv = r[0];
    for(i=1;i<n;i++){
        scanf("%d",&r[i]);
        if(maxv<r[i]-minv){
            maxv=r[i]-minv;
        }
        if(minv>r[i]){
            minv = r[i];
        }
    }
    printf("%d\n",maxv);
    return 0;
}

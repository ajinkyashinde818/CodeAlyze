#include<stdio.h>
long ans=-1000000000,min=1000000000,n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int r;
        scanf("%ld",&r);
        if(i!=0&&ans<r-min) ans=r-min;
        if(min>r) min=r;
    }
    printf("%ld\n",ans);
    return 0;
}

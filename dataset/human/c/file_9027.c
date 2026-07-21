#include<stdio.h>

int main(){
    int n , lim;
    scanf("%d %d",&n,&lim);
    int tall;
    int ans = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&tall);
        if(tall>=lim){
            ans++;
        }
    }
    printf("%d",ans);
    return 0;    

}

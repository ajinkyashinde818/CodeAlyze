#include<stdio.h>
int main(){
    int n,k,i;
    scanf("%d%d",&n,&k);
    int h[n],ans=0;
    for(i=0;i<n;i++){
        scanf("%d",&h[i]);
        if(h[i]>=k)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}

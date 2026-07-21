#include<stdio.h>
#include<string.h>
int main(void){
    int n,k,ans=0;
    scanf("%d%d",&n,&k);
    int h[n];
    for(int i=0;n>i;++i)
    scanf("%d",&h[i]);
    for(int i=0;n>i;++i){
        if(h[i]>=k)
        ++ans;
    }
    printf("%d",ans);
    return 0;
}
